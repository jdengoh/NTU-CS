from sense_hat import SenseHat
from sense_hat import SenseHat
sense = SenseHat()

import random
import time

acceleration = sense.get_accelerometer_raw()

rotate_no = [0, 90, 180, 270]

#for orientation, when usb ports are pointing below
# 0   -> arrow point right  -> x == 1
# 90  -> arrow point downwards (towards usb) -> x == 
# 180 -> arrow point left -> x == 0, y == -1.0
# 270 -> arrow points upwards -> x == 1.0, y == 0

b= (0, 0, 0)
y= (0, 250, 0)
r= (250, 0, 0)

green =\
    [b, b, b, b, b, b, b, b,
    b, b, b, y, b, b, b, b,
    b, b, y, y, y, b, b, b,
    b, y, b, y, b, y, b, b,
    b, b, b, y, b, b, b, b,
    b, b, b, y, b, b, b, b,
    b, b, b, y, b, b, b, b, 
    b, b, b, b, b, b, b, b]

red =\
    [b, b, b, b, b, b, b, b,
    b, b, b, r, b, b, b, b,
    b, b, r, r, r, b, b, b,
    b, r, b, r, b, r, b, b,
    b, b, b, r, b, b, b, b,
    b, b, b, r, b, b, b, b,
    b, b, b, r, b, b, b, b, 
    b, b, b, b, b, b, b, b]

error_count = 0

while error_count != 1:

    de_rotation = random.randint(0,3)

    rotate_1 = rotate_no[de_rotation]
    sense.set_rotation(rotate_1)
    sense.set_pixels(green)

    time.sleep(2)

    acceleration = sense.get_accelerometer_raw()

    x = acceleration['x']
    y = acceleration['y']
    z = acceleration['z']

    x_rounded = round(x,0)
    y_rounded = round(y,0)
    
    print('x = ', x_rounded)
    print('y = ', y_rounded)
    
    if rotate_1 == 0:
        if x_rounded == 0.0 and y_rounded == 1.0:
            pass
        else:
            sense.set_pixels(red)
            break


    elif rotate_1 == 90:
        if x_rounded == -1.0 and y_rounded == 0.0:
            pass
        else:
            sense.set_pixels(red)
            break
  
    elif rotate_1 == 180:
        if x_rounded == 0.0 and y_rounded == -1.0:
            pass
        else:
            sense.set_pixels(red)
            break
  
    
    elif rotate_1 == 270:
        if x_rounded == 1.0 and y_rounded == 0.0:
            pass
        else:
            sense.set_pixels(red)
            break
          
    sense.clear()
    time.sleep(0.5)

