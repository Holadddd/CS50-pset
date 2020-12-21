from cs50 import SQL
from sys import argv, exit

if (len(argv) != 2):
    sys.exit("Usage: roster.py House")
    
house = argv[1]

db = SQL("sqlite:///students.db")


rows = db.execute("SELECT * FROM students")

for row in rows:
    middle = ""
    
    if row["middle"] != None:
        middle = row["middle"]
    
    
    print(row["first"],"", middle,"", row["last"], ",", row["birth"], sep = ' ')
    