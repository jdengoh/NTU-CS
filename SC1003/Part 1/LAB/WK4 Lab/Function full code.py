#colour validate
#from ast import While
#from sense_hat import SenseHat
#from sense_hat import SenseHat
#sense = SenseHat()

def colour_check(colour_input, max):
    error_count1 = 0

    while error_count1 != 3:
        # isdigit check a string if it only has digits
        # for float, thre is a fullstop, so isdigit() returns False
        if error_count1 >=1:
            user_input1 = input('Enter the value of {} color for {}.'.format(color, bacc))
            colour_input = user_input1

        if colour_input == '####':
            print('Thank you for using the program, bye bye!')
            exit()
        
        if colour_input.isdigit() == False:
            error_count1 += 1
            print('Invalid - use number only ( {} )'.format(error_count1))
            continue
    
        if int(colour_input)>max:
            error_count1 += 1
            print('Invalid, value has to be between 0 and 255 ( {} )'.format(error_count1))
            continue
        else:
            break
    else:
        print('You have exceeded the number of trials allowed. Bye!')
        exit()
    
    return int(colour_input)

no_input = 0

#TEXT COLOUR INPUTS
while no_input != '####':

    text_red = input("Enter the value of red color of the message: ")
    color = 'red'
    bacc ='message'
    if text_red == '####':
        no_input = text_red
        continue
    checked_text_red = colour_check(text_red, 255)

    text_green = input("Enter the value of green color for message: ")
    color = 'green'
    bacc ='message'
    if text_green == '####':
        no_input = text_green
        continue
    checked_text_green = colour_check(text_green, 255)

    text_blue = input("Enter the value of blue color for message: ")
    color = 'blue'
    bacc ='message'
    if text_blue == '####':
        no_input = text_blue
        continue
    checked_text_blue = colour_check(text_blue, 255)

#BACKGROUND COLOR INPUTS
    bacc_red = input("Enter the value of red color for background: ")
    color = 'red'
    bacc ='background'
    if bacc_red == '####':
        no_input = bacc_red
        continue
    checked_bacc_red = colour_check(bacc_red, 255)

    bacc_green = input("Enter the value of green color for background: ")
    color = 'green'
    bacc ='background'
    if bacc_green == '####':
        no_input = bacc_green
        continue
    checked_bacc_red = colour_check(bacc_green, 255)

    bacc_blue = input("Enter the value of blue color for background: ")
    color = 'blue'
    bacc ='background'
    if bacc_blue == '####':
        no_input = bacc_blue
        continue
    checked_bacc_blue = colour_check(bacc_blue, 255)


else:
    print('Thank you for using the program, goodbye!')
    exit()
