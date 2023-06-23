def reverser(a_str):
    if len(a_str) == 1:	# base case
        return a_str
    else:				# recursive step
        new_str = reverser(a_str[1:]) + a_str[0]
        return new_str


def reverseAndRepeat(a_str, num):
    if len(a_str) == 1:	# base case
        return (a_str * num)
    else:				# recursive step
        new_str = reverseAndRepeat(a_str[1:], num) + (a_str[0] * num)
        return new_str

def reverseAndRepeat2(a_str, num):  # non-recursive version
    reversedStr = reverser(a_str)
    resultStr = ""

    for i in range(len(reversedStr)):
        resultStr = resultStr + (reversedStr[i] * num)
    
    return resultStr


def reverseAndOppositeCase(a_str):
    if len(a_str) == 1:	# base case
        if a_str.isupper():
            return a_str.lower()
        else:
            return a_str.upper()
    
    else:				# recursive step
        firstChar = a_str[0]
        if a_str[0].isupper():
            firstChar = a_str[0].lower()
        else:
            firstChar = a_str[0].upper()

        new_str = reverseAndOppositeCase(a_str[1:]) + firstChar
        return new_str        


def reverseAndOppositeCase2(a_str): # non-recursive version
    reversedStr = reverser(a_str)
    resultStr = ""

    for i in range(len(reversedStr)):
        if reversedStr[i].isupper():
            resultStr = resultStr + reversedStr[i].lower()
        else:
            resultStr = resultStr + reversedStr[i].upper()
    
    return resultStr


def symmetricString(a_str):
    if len(a_str) == 1:	    # base case
        return a_str + a_str

    else:                   # recursive step
        new_str = a_str[0] + symmetricString(a_str[1:]) + a_str[0]
        return new_str

def symmetricString2(a_str):    # non-recursive version
    suffix = reverser(a_str)

    return a_str + suffix


myStr = "AbCdE"

reversedStr = reverser(myStr)
reversedRepeatStr = reverseAndRepeat(myStr, 3)
reversedRepeatStr2 = reverseAndRepeat(myStr, 4)
reversedOppCaseStr = reverseAndOppositeCase(myStr)
reversedOppCaseStr2 = reverseAndOppositeCase2(myStr)
symmetricStr = symmetricString(myStr)
symmetricStr2 = symmetricString2(myStr)

print("reverse: ", myStr)
print("reversed and repeat 3 times: ", reversedRepeatStr)
print("reversed and repeat 4 times: ", reversedRepeatStr2)
print("reversed and opposite case: ", reversedOppCaseStr)
print("reversed and opposite case: ", reversedOppCaseStr2)
print("symmetric string: ", symmetricStr)
print("symmetric string: ", symmetricStr2)
