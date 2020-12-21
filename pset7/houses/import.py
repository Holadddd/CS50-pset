from sys import argv, exit
import itertools
import csv
import cs50
import sqlite3
import string
from cs50 import SQL

if len(argv) != 2:
    print("Wrong input.")
    exit()
    
db = SQL("sqlite:///students.db")

#Create the table

with open(argv[1], 'r') as csvFile:
    
    reader = csv.DictReader(csvFile, delimiter=",")
        
    for line in reader:
        
        splitName = line["name"].split()
        
        if len(splitName) == 2:
            #Do not have middle name
            # sql = "INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)"
            # val = (splitName[0], None, splitName[1], line["house"], line["birth"])
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", splitName[0], None, splitName[1], line["house"], line["birth"])
            
        elif len(splitName) == 3:
            #Do have middle name
            # sql = "INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)"
            # val = (splitName[0], splitName[1], splitName[2], line["house"], line["birth"])
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", splitName[0], splitName[1], splitName[2], line["house"], line["birth"])
            
exit()   