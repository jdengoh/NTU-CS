def bubblesort(user_input):

    for pass_num in range(len(user_input)-1): 
        #help break early
        swapped = False
        #inner loop more efficient(will not checked already sorted items at the end) 
        for i in range(len(user_input)-pass_num-1):
            if user_input[i] > user_input[i+1]:
                #the swap!
                temp_var = user_input[i]
                user_input[i] = user_input[i+1]
                user_input[i+1] = temp_var
                swapped = True
            
        print("pass", pass_num+1, ":", user_input)
        if not swapped:
            break


trial_1 = [2,43,23,5,96,3,25,40]

bubblesort(trial_1)

print(trial_1)