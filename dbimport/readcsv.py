# -*- coding: utf-8 -*-
from fileinput import filename
from os import replace
import sys
import csv
from os.path import exists, basename, isfile
from collections import defaultdict
from datetime import datetime, timedelta
import pandas as pd
from sqlalchemy import create_engine, true
from sqlalchemy import text
from pathlib import Path
from glob import glob
import os
import geopandas as gpd

def processWL(basePathSource, connString):
    # file_type = 'water*.csv' # exclude periods.csv
    file_type = '*.csv'
    csv_files = [y for x in os.walk(basePathSource) for y in glob(os.path.join(x[0], file_type))]
    # print(csv_files)

    # db connection
    engine = create_engine(connString)
    conn = engine.connect()

    # create db structure
    sqlfile = open(r'sql/create_object.sql', 'r')
    sql_create_object = sqlfile.read()
    sqlfile.close()
    conn.execute(sql_create_object)
    db_schema = 'wl'
    # db_import_schema = 'import'
    df_file_columns = ['filename','parameter','scenario','solution']
    # df_file = pd.DataFrame(columns=df_file_columns)

    # read shp file 
    shp_file = str(basePathSource) + r'/shp/areas.shp'
    print(shp_file)
    df_shp = gpd.read_file(shp_file)
    df_shp = df_shp.set_geometry('geometry')
    df_shp.rename(columns={'Nom_Senamh':'name', 'ID':'area_id'}, inplace=True)
    df_shp = df_shp[['area_id','name','km2','geometry']]
    # write shp to db
    df_shp.to_postgis('area', engine, schema=db_schema, if_exists='append', index=False)
    # define df_area for look up from scenario data
    df_area = df_shp[['area_id', 'name']]
    df_area = df_area.set_index('name')

    # read csv files
    for csv_fil in csv_files:
        # read file name
        filename = f"{basename(csv_fil)[0 : -1 - 3]}"

        print(filename)

        # read periods.csv separately
        if(filename=='periods'):
            df_period = pd.read_csv(csv_fil, delimiter=",", engine='python',header=0)
            df_period.rename(columns={'id': 'period_id','name': 'period_name','start': 'start_date', 'end': 'end_date'}, inplace=True)
            df_period.to_sql('period', engine, schema=db_schema, if_exists='append', index=False)

        else:
            print(filename)
            # split components (=filename, parameter, scenario, solution)
            file_components  = filename.split('_')      
            # cut off parameter after 4th character
            file_components[1] = file_components[1][:4]

            file_components.insert(0,filename)

            # read file properties
            df_file = pd.DataFrame(file_components).T
            df_file.columns = df_file_columns
            df_file.to_sql('file', engine, schema=db_schema, if_exists='append', index=False)

            # get insert file_id
            q = text('select file_id from wl.file where filename = (:fn)')
            res_fid = conn.execute(q,fn=filename)
            fileid = []
            for e in res_fid:
                fileid.append(e[0])
            fileid = fileid[0]

            # read file data
            df = pd.read_csv(csv_fil, delimiter=",", engine='python',header=0)
            dfm = pd.DataFrame(data=df)
            dfm = dfm.melt(id_vars=['area'],var_name='date',value_name='value')
            dfm.insert(0, 'file_id',value=fileid)
            # look up area_id
            dfm = df_area.join(dfm.set_index('area'),on=['name'])
            dfm = dfm[['file_id','area_id','date','value']]
            dfm.set_index(keys=['file_id', 'area_id'])
            # write scenariodata to db
            dfm.to_sql('scenariodata', engine, schema=db_schema, if_exists='append', index=False)

# TO DO:
# case_id toevoegen obv folder? (Lima... etc.)