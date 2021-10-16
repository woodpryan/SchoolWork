def reverseStr(strVal):
    if("unicorn" in strVal.lower()):
        return strVal[::-1]
    return strVal;

def addLand(strList):
    iIndex = 0

    for strVal in strList:
        strList[iIndex] = strVal + "land"
        iIndex+=1

def getKingdom(strAnimalList):
    strVal      = ""
    strKingdom  = ""
    dictKingdom = {}

    for strVal in strAnimalList:
        if(strVal.lower() == "newt"):
            strKindom = "Amphibian"
        elif(strVal.lower() == "snake"):
            strKingdom = "Reptile"
        elif(strVal.lower() == "bat"):
            strKingdom = "Mammal"
        dictKingdom[strVal] = strKingdom

    return dictKingdom;

def myMax(iList):
    iList.sort();
    return iList[-1];

def averageScores(playerScores):
    tplPlayer = ()
    strName   = ""
    iSum      = 0
    rAvg      = 0.0

    for tplPlayer in playerScores:
        strName = tplPlayer[0]
        iSum+= tplPlayer[1]

    rAvg = iSum/len(playerScores)

    return rAvg;

class Worker:
    def work:
        #...does some work
    def takeBreak:
        #...takes a break for food and other rest

class DedicatedWorker(Worker):
    def work:
        # ..does some extra work
    def takeBreak:
        # ...takes a shorter break and eats at desk

class Robot(Worker):
    def work:
        # .. does a bunch of work
    def takeBreak:
        # ... pauses work for maintenance or mechanical rest

class Manager:
        def setWorker(w):
            worker = w
        def mainage:
            worker.work

strVal = "my favorite unicorn"
strRev = reverseStr(strVal)
print(strRev)

strList = ["fat", "bat"]
addLand(strList)
print(strList)

strAnimals  = ["bat", "newt", "snake"]
dictKingdom = getKingdom(strAnimals)

print(dictKingdom)
iList = [4, 20, 52, 45, 29]
iHighest = myMax(iList)
print(iHighest)

playerScores = [ ("Smith", 92), ("Jones", 89), ("Andrews", 90), ("Smith", 100) ]
print(averageScores(playerScores))
