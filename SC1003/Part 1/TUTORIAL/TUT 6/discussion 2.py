
def reverseAndOppositeCase(my_str):

    str_list = [i for i in my_str]


    if len(my_str) == 1:
        #can immediately return in the loop itself
        if str_list[0].isupper() == False:
            str_list[0] = str_list[0].upper()
        else:
            str_list[0] = str_list[0].lower()
        
        my_str = str_list[0]
        return my_str
    
    else:
        #change the [0] character first, then the rest will go through the "recursive" function again

        if str_list[0].isupper() == False:
            str_list[0] = str_list[0].upper()
        else:
            str_list[0] = str_list[0].lower()
        
        new_str = ''.join(str_list)
   
        new_str = reverseAndOppositeCase(new_str[1:]) + new_str[0]

        return new_str


print(reverseAndOppositeCase('tHiS iS iN aLtErNaTe CaPs'))