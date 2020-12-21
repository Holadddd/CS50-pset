from sys import argv, exit
import itertools
import csv
import re

# 2 input argument
if len(argv) != 3:
    print("Wrong input.")
    exit()
#The list of nucleotide bases
dataDicArr = []

dnalist = []

with open(argv[1], 'r') as csvFile:
    
    for line in csv.DictReader(csvFile):
        dataDicArr.append(line)
        
with open(argv[1], 'r') as csvFile:
    
    reader = list(csv.reader(csvFile))
    
    reader[0].remove("name")
    
    dnalist = reader[0]
    
#The counts of sequence with perspective nucleotide
sequenceValue = {}

sequenceFileDir = argv[2]

sequenceFile = open(sequenceFileDir, "r")

sequenceText = sequenceFile.read()

sequenceTextLength = len(sequenceText)

for (_, element) in enumerate(dnalist):
    finalMaxCounts = 0
    
    tmpMaxCount = 0
    
    dnaMoleculesCounts = len(element)
    #index with sequence
    index = 0
    #Mapping with the sequence
    while (index + dnaMoleculesCounts) <= sequenceTextLength:
        #Part of the sequence 
        tmpDna = ""
        
        for (j, _) in enumerate(element):
            tmpDna += sequenceText[index + j]
                
        #Check the part of sequence is matching the dna
        if tmpDna == element:
            tmpMaxCount += 1
            #shift the index on sequence
            index += dnaMoleculesCounts
        else:
            #reset the tmp max counts
            tmpMaxCount = 0
            #shift the index on sequence
            index += 1
            
         #update the max counts
        if tmpMaxCount > finalMaxCounts:
            finalMaxCounts = tmpMaxCount
            
    #update the sequence dictionary
    sequenceValue[element] = finalMaxCounts

# print("SeqValue:",sequenceValue)
#Matching with the database
for element in dataDicArr:
    match = True
    #match each dna
    for dna in dnalist:
        countOfData = element[dna]
        
        countOfSequence = sequenceValue[dna]
        
        # print("countOfData", countOfData, "countOfSequence", countOfSequence)
        if int(countOfData) != int(countOfSequence):
            match = False
         
    if match:
        print(element["name"])
        exit()

print("No match")