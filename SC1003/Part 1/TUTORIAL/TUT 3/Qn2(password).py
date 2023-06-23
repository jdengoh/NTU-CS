# 1. Set all variable to False first.
#       - if condition satisfied, change variable to true
#       - otheriwse, the condition remains false

valid_or_not = False

while valid_or_not != True:

    # must define variables again inside while loop!
    length_valid = False
    uppercase_valid = False
    lowercase_valid = False
    number_valid = False

    password = input("Please enter your password: ")

    if len(password) >= 8:
        length_valid = True
    else:
        print('*Please enter a password with more that 8 characters.')

#check for various conditions, such as upper, lower case, number, etcc..

    for char in password:   
        if char.isupper() == True:
            uppercase_valid = True
        if char.isdigit() == True:
            number_valid = True
        if char.islower() == True:
            lowercase_valid = True
    
    if uppercase_valid == False:
        print('*Please enter at least 1 capital letter')
    if number_valid == False:
        print('*Please enter at least 1 number,')
    if lowercase_valid == False:
        print('*Please enter at least 1 lower-case letter.')

    valid_or_not = length_valid and uppercase_valid and number_valid and lowercase_valid

    if valid_or_not == True:
        print('Your password is strong.')
        break
    
    else:
        print('Your password is weak. Please set a new password.')
        continue



#HOW TO IMPLEMENT A NUMBER IN THERE??
#HOW TO IMPLEMENT CAPS IN THERE??


#isupper()
#islower()
#isdigit() vs #isnumeric()
