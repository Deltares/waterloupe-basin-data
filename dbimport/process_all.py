import readcsv
from pathlib import Path
from sqlalchemy import create_engine

basePathSource = Path(r"N:/Projects/1230000/1230409/B. Measurements and calculations/26.dashboarddata/")
# to only re-create db views and funtions: processData=False; to process all data: processData=True
processData = True
connString = 'postgresql://pg:pg@localhost:5432/waterloupe'

# db connection
engine = create_engine(connString)
conn = engine.connect()

readcsv.processWL(basePathSource, connString, processData)
