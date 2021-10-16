
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
        tpl = (iXCoord, iYCoord)
        tplList.append(tpl)

    return tplList





strFile = "e2p2data.csv"
coordList = getCoordinateList(strFile)
print(coordList)
