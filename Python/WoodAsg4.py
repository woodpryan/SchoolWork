def countWords(strArray):
    """This function counts the number of times each unique word shows up in the
       given array of words"""

    dictWords = {}
    count     = 1

    for word in strArray:
        count = 1
        if word in dictWords:
            count = dictWords[word]
            count = count+1
        dictWords[word] = count

    for word in dictWords:
        count = dictWords[word]
        if count > 1:
            print("The word " + word + " was found " + str(count) + " times.")
        else:
            print("The word " + word + " was found " + str(count) + " time.")
    return;

def monthToNum(strMonth):
    dictMonth = {
            'jan'       : 1,
            'january'   : 1,
            'feb'       : 2,
            'february'  : 2,
            'mar'       : 3,
            'march'     : 3,
            'apr'       : 4,
            'april'     : 4,
            'may'       : 5,
            'jun'       : 6,
            'june'      : 6,
            'jul'       : 7,
            'july'      : 7,
            'aug'       : 8,
            'august'    : 8,
            'sep'       : 9,
            'september' : 9,
            'oct'       : 10,
            'october'   : 10,
            'nov'       : 11,
            'november'  : 11,
            'dec'       : 12,
            'december'  : 12
    }
    iMonth   = -1
    strLower = strMonth.lower()
    if strLower in dictMonth:
        iMonth = dictMonth[strLower]
    return iMonth;

from calendar import monthrange
def printCalendar(month, day):
    """Given a month a a day of the week, this function prints the calender for the month"""

    strDays = "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"
    iMonth  = monthToNum(month)

    if iMonth == -1:
        print("Did not recognize the month entered.")
        return;
    if day.lower() not in strDays:
        print("Did not recognize the day entered.")
        return;
    
    strDay   = ""
    mRange   = monthrange(2019, iMonth)
    iNumDays = mRange[1]
    printNum = False
    strWeek  = ""
    iCount   = 1

    print("The calendar for a " + month + " beginning on a " + day + " would look like this:")
    while iCount <= iNumDays:
        for strDay in strDays:
            if strDay.lower() == day.lower():
                printNum = True
            if iCount > iNumDays:
                break
            if printNum == False:
                strWeek = "\t" + strWeek
            else:
                strWeek = strWeek + str(iCount) + "\t"
                iCount += 1
        print(strWeek)
        strWeek = ""

    return;

strWords = "bleh", "Brah", "lah", "bleh"
countWords(strWords);

strMonth = raw_input("Please enter a month of the year: ")
strDay   = raw_input("Please enter a day of the week: ")
printCalendar(strMonth, strDay)

strCount = raw_input("Please enter a word or phrase: ")
print("You entered the string: " + strCount)
print("The number of characters in the string = " + str(len(strCount)))

