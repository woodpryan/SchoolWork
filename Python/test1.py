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

tplList = [(1, 2), (5, 2), (0, 3)]
val     = getPointRelation(tplList)

print(val);

tplList2 = [(1, 2), (5, 2), (2, 0)]
val      = getPointRelation(tplList2)

print(val);

