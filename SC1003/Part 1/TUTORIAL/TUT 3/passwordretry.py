special_char = '''`~!@#$%^&*()_-+={[}]|\:;"'<,>.?/'''

final_check = False

while final_check!=True:

    pass_in = input('Please enter your password: ')

    length_check = False
    digit_check = False
    upper_check = False
    lower_check = False
    special_check = False

    if len(pass_in) >= 8:
        length_check = True
    else:
        print('Use at least 8 characters.')
    
    for i in pass_in:
        if i.isdigit():
            digit_check = True
            break
    else:
        print('Include numbers.')

    for j in pass_in:
        if j.isupper():
            upper_check = True
            break
    else:
        print('Include upper case alphabet')
    
    for k in pass_in:
        if k.islower():
            lower_check = True
            break
    else:
        print('Include lower case alphabets.')
    
    for i in special_char:
        for j in pass_in:
            if i == j:
                special_check = True
                break
        
        if special_check:
            break
    else:
        print('Include special characters.')

    final_check = digit_check and upper_check and lower_check and special_check and length_check

    if final_check:
        print('Your password is strong!')
    else:
        print('Your password is weak, please try again.')