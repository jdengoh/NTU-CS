#from sense_hat import SenseHat
#sense = SenseHat()
#sense.set_rotation(180)

def get_color(color):
    tries = 1
    
    while tries <=3:

        color1 = input('Enter the value of {color} colour for message from 0 to 255: ')

        if color1.isdigit() is True:
            pass
        else:
            print('Please enter an integar only.')
            tries+=1
            continue

        if 0<int(color1)<255:
            break

        else:
            print('Please enter an integar between 0 and 255.')
            tries += 1
            continue
    else:
        print('You have exceeded number of tries. {color} will be set to 0')
        color1 = '0'

    return int(color1)


red = get_color('red')

print(red)