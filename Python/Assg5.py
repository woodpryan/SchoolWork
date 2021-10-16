#   File:       Assg5.py
#   Author:     Ryan Wood
#   Created:    October 10, 2020

import random

#Problem number 1
def occurrences(lstObjects, objVal):
    """This function returns a new list where all elements are the items from
       the given list that have the given value"""
    lstNew = []

    for itm in lstObjects:
        if itm == objVal:
            lstNew.append(itm)

    return lstNew;

#Problem number 2
def numSmaller(lstItems, elem):
    """This function returns the number of items in the given list that equal less than
       the given value"""
    count = 0

    for lstIter in lstItems:
        if lstIter < elem:
            count+= 1
    return count;

#Problem number 3
def secondSmallest(lstItems):
    """This function determines what is the index of the second smallest item in the list or,
       if the list contains more than one of the smallest item, the second index of that item"""
    
    if len(lstItems) == 0:
        return -1;
    
    index       = 0#current index in the list
    returnNext  = False;#return the next occurence of a value equal to valSmallest
    valSmallest = lstItems[0]#just declaring and initializing valSmallest

    for val in lstItems:
        if returnNext == True and val == valSmallest:
            return index;

        if numSmaller(lstItems, val) == 0 and len(occurrences(lstItems, val)) > 1:
            returnNext = True;
            valSmallest = val
        elif numSmaller(lstItems, val) == 1:
            iSecondSmallest = index;
        index+= 1

    return iSecondSmallest;

#frequencyTable, pulled from the homework specification
def frequencyTable (dnaList):
    """This function prints a frequency table for the given gene sequence"""
    n = max([len(dna) for dna in dnaList])
    frequency_matrix = {
        'A': [0]*n,
        'C': [0]*n,
        'G': [0]*n,
        'T': [0]*n,
    }
    for dna in dnaList:
        for index , base in enumerate(dna):
            frequency_matrix[base][index] += 1

    return frequency_matrix;

#problem number 4
def getGeneLetter():
    """This function generates a random letter out of four gene letters"""
    iRand = random.randint(0, 3)
    if iRand == 0:
        return 'A'
    elif iRand == 1:
        return 'C'
    elif iRand == 2:
        return 'G'
    elif iRand == 3:
        return 'T'
    return '';

#problem number 4
def mutate(strDna):
    """This function mutates the given string of DNA, randomly replacing characters"""
    
    strGene = strDna
    for iCount in range(len(strDna)):
        cRandChar = getGeneLetter()
        cReplace  = random.choice(strGene)

        strGene = strGene.replace(cReplace, cRandChar, 1)
    return strGene

##problems number 5 and 6
import fileinput
def getBusSchedule():
    """This function will read the busRoutes.txt input file and create a list of
       bus stops and stop times"""
    isFirstWord = True
    inFile      = fileinput.input(files=('busRoutes.txt'))
    strWord     = ""
    index       = 0
    dictStops   = {}
    strStops    = []

    for line in inFile:
        isFirstWord = True
        index       = 0
        for strWord in line.split():
            #skip the Bus number
            if isFirstWord:
                isFirstWord = False
                continue

            #skip the colons
            if strWord == ":":
                continue

            if inFile.isfirstline():
                lstTimes = []
                dictStops[strWord] = lstTimes;
                strStops.append(strWord);
            else:
                lstTimes = dictStops[strStops[index]]
                lstTimes.append(strWord)
                dictStops[strStops[index]] = lstTimes;
            index+=1
        #for word in line
    #for line in file
    return dictStops;

#Problem number 5
def printSchedule(dictBusSchedule):
    """This function will print the given bus schedule in the format
       stopName : time:time:time"""

    strPrint = ""
    for strStop in dictBusSchedule:
        strPrint = ""
        lstTimes = dictBusSchedule[strStop]
        for strTime in lstTimes:
            if strPrint == "":
                strPrint = strStop + ": " + strTime
            else:
                strPrint = strPrint + ":" + strTime

        print(strPrint)

random.seed()
strGene = ""

#Problem number six
def printEnumeratedSchedule(dictSchedule):
    """This function uses the enumerate function and the print function's formatting
       feature to print the bus schedule"""
    for i, (strStop, val) in enumerate(dictSchedule.items()):
        print(strStop, *val, sep=":")

#This is a test of problem number 1
lstObjects = ["test1", "boo", "Happy Halloween", "Ghostly", "test1", "Spooky", "Cooky", "test1"]
lstNew     = occurrences(lstObjects, "test1");

strItm = ""
for strItm in lstNew:
    print(strItm)

##problem number 2 test
print(numSmaller(lstObjects, "test1"))

#problem number 3 test
lstInt = [4, 7, 5, 6, 8, 3, 2]
print(secondSmallest(lstInt))

#problem number 4
#get 20 random gene letters
for iCount in range(20):
    strGene = strGene + getGeneLetter()

freqMatrix = frequencyTable(strGene)
print(freqMatrix)

strGene = mutate(strGene)

freqMatrix = frequencyTable(strGene)
print(freqMatrix)

#problem number 5
dictBusSchedule = getBusSchedule()
printSchedule(dictBusSchedule)

#problem number 6
printEnumeratedSchedule(dictBusSchedule);
