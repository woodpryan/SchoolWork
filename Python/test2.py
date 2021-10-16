def getPointRelation(tplList):
    tplX = ()
    tplY = ()
    tplZ = ()

    tplX = tplList[0];
    tplY = tplList[1];
    tplZ = tplList[2];

    a = tplY[1] - tplY[0]
    b = tplX[0] - tplX[1]
    c = (tplX[0] * tplY[1]) - (tplX[1] * tplY[0])
    
    pointRel = (a * tplZ[0]) + (b * tplZ[1]) - c
    return pointRel;

import fileinput
def getCoordinateList(strFileName):

    inFile  = fileinput.input(files=(strFileName))
    tplList = []
    
    for strLine in inFile:
        strCoordList = strLine.split()
        strX = strCoordList[0]
        strY = strCoordList[2]

        iXCoord = int(strX)
        iYCoord = int(strY)
        tpl     = (iXCoord, iYCoord)

        tplList.append(tpl)

    return tplList

def getChull(coordList):
    cHull = []
    #for each point in the list
    for tplPoint1 in coordList:
        #for each point in the list other than the current first point
        for tplPoint2 in coordList:
            if(tplPoint2 == tplPoint1):
                continue
            #for each point other than the first and second points
            for tplPoint3 in coordList:
                if(tplPoint3 == tplPoint2 or tplPoint3 == tplPoint1):
                    continue
                #determine if this third point is above, below, or on the line between 1st and 2nd points
                tplList    = [tplPoint1, tplPoint2, tplPoint3]
                iRelation  = getPointRelation(tplList);
                dictPoints = {}
                if(iRelation > 0):
                    dictPoints["Above"] = tplPoint3
                elif(iRelation < 0):
                    dictPoints["Below"] = tplPoint3
                else:
                    dictPoints["On"] = tplPoint3;
            #if all points are on one side of the line, then add the first
             #and second points to a list of points on the c-hull
            if(len(dictPoints) == 1):
                cHull.append(tplPoint1)
                cHull.append(tplPoint2)
    return cHull;

   

strFile   = "e2p2data.csv"
coordList = getCoordinateList(strFile)

print(coordList)

cHull = getChull(coordList)
print(cHull);


