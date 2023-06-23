import random

#divide problem into smaller problem
#

random_no = str(random.randint(0, 9999)).zfill(4)

#can do (bull, cow) -> make a tuple
#can do global variable
    
bull = [0]
cow = [0]

def no_checker(random_no, input_no, bull, cow):


#convert into list first
    list_random = []
    for j in range(len(random_no)):
        list_random.append(random_no[j])
    #print(list_random)

    list_input = []
    for k in range(len(input_no)):
        list_input.append(input_no[k])
    #print(list_input)

    for i in range(len(list_random)):
        if list_input[i] == list_random[i]:
            bull[0]+=1
            list_random[i] = 'no'
            list_input[i] = 'yas'
            continue
        else:
            continue

    #print(list_random)
    #print(list_input)

    for i in range(len(list_random)):
        if list_input[i] in list_random:
            cow[0]+=1
            x = list_random.index(list_input[i])
            list_random[x] = 'no'
        else:
            continue

    #print(list_random)
    #print(list_input)

attempt = 0

while bull[0] != 4:
    user_in = input("Please input 4 digits: ")
    no_checker(random_no, user_in, bull, cow)
    print('{} A (Bulls)  {} B (Cows)'.format(bull[0],cow[0]))
    if bull[0] == 4:
        continue
    bull = [0]
    cow = [0]
    attempt+=1
else:
    print('You Win!!\nAttempts= {}'.format(attempt))
