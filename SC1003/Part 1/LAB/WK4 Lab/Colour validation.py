#colour validate
from sense_hat import SenseHat
from sense_hat import SenseHat
sense = SenseHat()

error_count1 = 0
while error_count1 != 3:
    text_red = input('Enter the value of red color for message: ')
    
    # isdigit check a string if it only has digits
    # for float, thre is a fullstop, so isdigit() returns False

    if text_red.isdigit() == False:
        error_count1 += 1
        print('Invalid - use number only ( {} )'.format(error_count1))
        continue
    
    if int(text_red)>255:
        error_count1 += 1
        print('Invalid, value has to be between 0 and 255 ( {} )'.format(error_count1))
        continue
    else:
        break
else:
    print('You have exceeded the number of trials allowed. Bye!')
    exit()
int_text_red = int(text_red)


#GREEN1
error_count2 = 0
while error_count2 != 3:
    text_green = input('Enter the value of green color for message: ')

    if text_green.isdigit() == False:
        error_count2 += 1
        print('Invalid - use number only ( {} )'.format(error_count2))
        continue
    
    if int(text_green)>255:
        error_count2 += 1
        print('Invalid, value has to be between 0 and 255 ( {} )'.format(error_count2))
        continue
    else:
        break
else:
    print('You have exceeded the number of trials allowed. Bye!')
    exit()
int_text_green = int(text_green)


#BLUE1
error_count3 = 0
while error_count3 != 3:
    text_blue = input('Enter the value of blue color for message: ')

    if text_blue.isdigit() == False:
        error_count3 += 1
        print('Invalid - use number only ( {} )'.format(error_count3))
        continue
    
    if int(text_blue)>255:
        error_count3 += 1
        print('Invalid, value has to be between 0 and 255 ( {} )'.format(error_count3))
        continue
    else:
        break
else:
    print('You have exceeded the number of trials allowed. Bye!')
    exit()
int_text_blue = int(text_blue)


#RED2
error_count4 = 0
while error_count4 != 3:
    bg_red = input('Enter the value of red color for background: ')

    if bg_red.isdigit() == False:
        error_count4 += 1
        print('Invalid - use number only ( {} )'.format(error_count4))
        continue
    
    if int(bg_red)>255:
        error_count4 += 1
        print('Invalid, value has to be between 0 and 255 ( {} )'.format(error_count4))
        continue
    else:
        break
else:
    print('You have exceeded the number of trials allowed. Bye!')
    exit()
int_bg_red = int(bg_red)


#GREEN2
error_count5 = 0
while error_count5 != 3:
    bg_green = input('Enter the value of green color for background: ')

    if bg_green.isdigit() == False:
        error_count5 += 1
        print('Invalid - use number only ( {} )'.format(error_count5))
        continue
    
    if int(bg_green)>255:
        error_count5 += 1
        print('Invalid, value has to be between 0 and 255 ( {} )'.format(error_count5))
        continue
    else:
        break
else:
    print('You have exceeded the number of trials allowed. Bye!')
    exit()
int_bg_green = int(bg_green)


#BLUE2
error_count6 = 0
while error_count6 != 3:
    bg_blue = input('Enter the value of blue color for background: ')

    if bg_blue.isdigit() == False:
        error_count6 += 1
        print('Invalid - use number only ( {} )'.format(error_count6))
        continue
    
    if int(bg_blue)>255:
        error_count6 += 1
        print('Invalid, value has to be between 0 and 255 ( {} )'.format(error_count6))
        continue
    else:
        break
else:
    print('You have exceeded the number of trials allowed. Bye!')
    exit()
int_bg_blue = int(bg_blue)

#speed
valid_speed = False

while valid_speed != True:
    in_speed = input('Enter the value of the display speed: ')
    
    try:
        float(in_speed)
    except:
        print('Invalid - enter number only')
        continue

    if 0.05>float(in_speed) or 1<float(in_speed):
        print('Invalid - value has to be between 0.05 and 1')
        continue
    else:
        valid_speed = True

else:
    float_speed = float(in_speed)

print('Speed = {}'.format(float_speed))

sense.show_message("Hello", text_colour=(int_text_red,int_text_green,int_text_blue), back_colour=(int_bg_red,int_bg_green,int_bg_blue), scroll_speed = float_speed)
sense.clear(0, 0, 0)

