#group -> class name
#id -> register no. from 1-40
#score -> marks from 1-100, linked to 1 reg no.

one_class = {}
database = {}

def inputRecord(database, group, id, score):
    right_entry = 0
    one_class = {}

    while right_entry != '####':

        if right_entry >0:
            group = input('Please input the class again: ')
            id = input('Please input the register number again: ')
            score = input('Please input the score again: ')
    
    #while True -> make an infinite loop, use break to exit or continue to loop again

        try: 
            int(id)
        except:
            print('Please input a number for the id.')
            right_entry += 1
            continue
        
        if id.isdigit() == False:
            print('Please input a whole number.')
            right_entry += 1
            continue

        if int(id)>40:
            print('Please input a number within range of 1 to 40.')
            right_entry += 1
            continue

        try:
            int(score)
        except:
            print('Please input a number for the score.')
            right_entry += 1
            continue

        if int(score) > 100:
            print('Please input a number within range of 0 to 100.')
            right_entry += 1
            continue
        
        
        if group.isalpha() == False:
            print('Please input a string for the class name.')
            right_entry += 1
            continue
        else:
            group = group.upper()
        
        #dictionary part
        one_class = {}
        one_class [id] = score

        if group in database:
            database[group].update(one_class)
        else:
            database[group] = one_class
        break
    
    print(database.items())
    
def query(database,group, id):
    error_count1 = 0
    while True:
        if error_count1 >0:
            group = input('Please input the class again.')
            id = input('Please input the register number again.')

        try:
            print(database[group][id])
            break

        except:
            print('Error. Please try again.')
            error_count1 +=1
            continue

def listgrades(database, group):
    error_count2 = 0
    while True:
        if error_count2 >0:
            group = input('Please input the class again.')

        try:
            print(database[group].values())
            break

        except:
            print('Error. Please try again.')
            error_count2 +=1
            continue

def maxgrade(database, group):
    error_count3 = 0
    while True:
        if error_count3 >0:
            group = input('Please input the class again.')
        try:
            grade_list = list(database[group].values())
            grade_list.sort()
            print('The highest grade in the class is {}.'.format(grade_list[-1]))
            break
        except:
            print('Error. Please try again.')
            error_count3 +=1
            continue


print('Welcome to the grading system!')
run_condition = 0
error_count4 = 0

while run_condition != 5:
    
    if error_count4>0:
        run_condition = input('option: ')
    else:
        run_condition = input('Please enter your option:\n\
1: input record\n\
2: querry a student \n\
3: list grades in a group\n\
4: get max in a group\n\
5. exit\n\
option: ')
    
    try:
        int(run_condition)
        errorcount4 = 0
    except:
        print("Please re-enter your option: ")
        error_count4 += 1
        continue
    
    if int(run_condition)<1 or int(run_condition)>5:
        error_count4 += 1
        print('Please enter a number from 1 to 5.')
        continue
    else:
        error_count4 = 0


    if int(run_condition) == 1:
        the_class = input('What is the class?')
        reg_no = input('What is the register no.?')
        the_score = input('What is the score?')

        inputRecord(database, the_class, reg_no, the_score)
        continue

    if int(run_condition) == 2:
        query_class = input('Class?')
        query_id = input('Register number?')

        query(database, query_class, query_id)
        continue

    if int(run_condition) == 3:
        listclass = input('Class?')
       
        listgrades(database, listclass)
        continue

    if int(run_condition) == 4:
        maxclass = input('Class?')
        
        maxgrade(database, maxclass)
        continue
    
    if int(run_condition) == 5:
        print('Thank you for using the program!')
        exit()


    
    
#FOR MY TESTING
    
    #maxclass = input('Class?')
    #maxgrade(database, maxclass)
    
    #listclass = input('Class?')
    #listgrades(database, listclass)

    #query_class = input('Class?')
    #query_id = input('Register number?')

    #query(database, query_class, query_id)