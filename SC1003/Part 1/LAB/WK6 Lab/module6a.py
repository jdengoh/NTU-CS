from sense_hat import SenseHat
sense = SenseHat()
sense.set_rotation(180)

def get_color(color):
    error_count = 0

    while error_count != 3:
        color_str=input("Enter the value of the " + color + \
                        " color for message (0 to 255):")
        
        if color_str.isdigit() == False:
            error_count += 1
            print('Invalid - use number only ( {} )'.format(error_count))
            continue
    
        if int(color_str)>255 or int(color_str)<0:
            error_count += 1
            print('Invalid, value has to be between 0 and 255 ( {} )'.format(error_count))
            continue
        else:
            break
    else:
        print('You have exceeded the number of trials allowed. {} will be set to 0'.format(color))
        color_str = '0'
    
    return int(color_str)

#r_int = get_color("red")
#g_int = get_color("green")
#b_int = get_color("blue")
#msg_color = (r_int, g_int, b_int)
#sense.show_message("I got it!", text_colour=msg_color)