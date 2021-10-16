import random

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


random.seed()
strGene = ""
iCount  = 0

#get 1000 random gene letters
for iCount in range(1000):
    strGene = strGene + getGeneLetter()

freqMatrix = frequencyTable(strGene)
print(freqMatrix)
print('\n')

# Randomly replace 100 of the gene letters
for iCount in range(100):
    cRandChar = getGeneLetter()
    cReplace  = random.choice(strGene)

    strGene = strGene.replace(cReplace, cRandChar, 1)

freqMatrix = frequencyTable(strGene)
print(freqMatrix)


