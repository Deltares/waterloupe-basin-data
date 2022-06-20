import readcsv
from pathlib import Path
from sqlalchemy import create_engine

basePathSource = Path(r"D:/waterloupe/Peru/csv/")
connString = 'postgresql://pg:pg@localhost:5432/waterloupe'

# db connection
engine = create_engine(connString)
conn = engine.connect()

readcsv.processWL(basePathSource, connString)
