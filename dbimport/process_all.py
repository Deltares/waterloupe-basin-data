import readcsv
from pathlib import Path
from sqlalchemy import create_engine

basePathSource = Path(r"N:/Projects/1230000/1230409/B. Measurements and calculations/26.dashboarddata/")
connString = 'postgresql://pg:pg@localhost:5432/waterloupe'

# db connection
engine = create_engine(connString)
conn = engine.connect()

readcsv.processWL(basePathSource, connString)
