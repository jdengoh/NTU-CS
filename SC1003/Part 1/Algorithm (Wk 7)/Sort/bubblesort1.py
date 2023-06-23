def bubblesort(user_input):

    for pass_num in range(len(user_input)-1):
        for i in range(len(user_input)-1):
            if user_input[i] > user_input[i+1]:
                #the swap!
                temp_var = user_input[i]
                user_input[i] = user_input[i+1]
                user_input[i+1] = temp_var


trial_1 = [43,23,5,96,3,2,4,25,40]

bubblesort(trial_1)

print(trial_1)