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

def processWL(basePathSource, connString, processData):
    # db connection
    engine = create_engine(connString)
    conn = engine.connect()

    # read main folders (each folder is one case)
    cases = [f.name for f in os.scandir(basePathSource) if f.is_dir()]
    print(cases)

    for case in cases:
        print(case)
        casePathSource = basePathSource.joinpath(case)
        db_schema = case

        if(processData):
            # create db structure: db-schema per case
            print('create database tables')
            sqlfile = open(r'sql/create_object.sql', 'r')
            sql_create_object = sqlfile.read()
            sqlfile.close()
            sql_create_object = sql_create_object.replace(r"{db_schema}", db_schema)
            # print(sql_create_object)
            conn.execute(sql_create_object)
            df_file_columns = ['filename','parameter','users','scenario','solution']

            # read shp file 
            shp_file = str(casePathSource) + r'/shp/areas.shp'
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
            file_type = '*.csv'
            csv_files = [y for x in os.walk(casePathSource) for y in glob(os.path.join(x[0], file_type))]
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
                    # split components (=filename, parameter, users, scenario, solution)
                    file_components  = filename.split('_')      
                    file_components.insert(0,filename)

                    # read file properties
                    df_file = pd.DataFrame(file_components).T
                    df_file.columns = df_file_columns
                    df_file.to_sql('file', engine, schema=db_schema, if_exists='append', index=False)

                    # get insert file_id
                    q = text('select file_id from ' +db_schema+ '.file where filename = (:fn)')
                    res_fid = conn.execute(q, schema=db_schema,fn=filename)
                    fileid = []
                    for e in res_fid:
                        fileid.append(e[0])
                    fileid = fileid[0]

                    # read file data
                    df = pd.read_csv(csv_fil, delimiter=",", engine='python',header=0)
                    dfm = pd.DataFrame(data=df)
                    # treat data with period columns (usually 4 periods) different than data with date columns (>=12)
                    if len(dfm.columns) < 10:
                        time_column = 'period_id'
                    else: 
                        time_column = 'date'
                    dfm = dfm.melt(id_vars=['area_id'],var_name=time_column,value_name='value')
                    # include file-id in df
                    dfm.insert(0, 'file_id',value=fileid)
                    dfm = dfm[['file_id','area_id',time_column,'value']]
                    dfm.set_index(keys=['file_id', 'area_id'])
                    # write scenariodata to db
                    dfm.to_sql('scenariodata', engine, schema=db_schema, if_exists='append', index=False)

        # (re-)create db views and functions per case
        print('(re-)create database views and functions')
        sqlfile_view = open(r'sql/create_view.sql', 'r')
        sql_create_view = sqlfile_view.read()
        sqlfile_view.close()
        sql_create_view = sql_create_view.replace(r"{db_schema}", db_schema)
        # print(sql_create_view)
        conn.execute(sql_create_view)

