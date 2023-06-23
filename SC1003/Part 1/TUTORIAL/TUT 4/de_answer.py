def read_data():
    groupName = input("Please input group name: ")
    sID = int(input('Please input the student id: '))
    score = int(input('Please input the score: '))
    
    return {('group'):groupName,
        ('ID'):sID
        ('score'):score
        }

def insertRecord(dataBase, group, id, score):
    dataKey = (group, id)
    dataBase[dataKey] = score

def inputRecord(database, group, id, score):
    data = {}
    data = read_data()
    while data['score'] !=1:
        insertRecord(grades, )
