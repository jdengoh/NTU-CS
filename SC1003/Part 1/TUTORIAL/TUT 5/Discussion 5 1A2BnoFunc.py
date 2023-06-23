import random


answerList = random.sample([1,2,3,4,5,6,7,8,9,0], 4)
print (answerList)

while True:
    inputStr = input("Please input 4 digits: ")
    while inputStr.isdigit() == False or len(inputStr) != 4:
        inputStr = input("Wrong format!! Please input 4 digits: ")

    guessList = []

    for i in range(4):
        num = int(inputStr[i])
        guessList.append(num)

    bulls = 0
    cows = 0

    for j in range(len(answerList)):
        for i in range(len(guessList)): 
            if guessList[i] == answerList[j]:
                if i == j:
                    bulls += 1
                else:
                    cows += 1

    if bulls == 4:
        print("You Win!!")
        break
    else:
        print(bulls, "A (Bulls)", cows, "B (Cows)")
    
