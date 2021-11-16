from pathlib import Path
import pandas as pd
import json

def xlsx2json(file):
    data = pd.read_csv(file.resolve(), skiprows=1, nrows=27, encoding='utf8')
    print(data)

file = Path(r'D:\voorCindy\data\availability\superficial\availab_surf.xlsx')
line_chart_template = 'line_chart_template.json'
xlsx2json(file)
