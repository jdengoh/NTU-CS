from sense_hat import SenseHat
sense = SenseHat()
import random
import time

sense.clear()

rotate_no = [0, 90, 180, 270]

while True:
    x1 = random.randint(0,3)

    r2 = random.randint(0,255)
    g2 = random.randint(0,255)
    b2 = random.randint(0,255)

    b= (0, 0, 0)
    y= (r2, g2, b2)

    image_pixels_1 =\
    [b, b, b, b, b, b, b, b,
    b, b, b, y, b, b, b, b,
    b, b, y, y, y, b, b, b,
    b, y, b, y, b, y, b, b,
    b, b, b, y, b, b, b, b,
    b, b, b, y, b, b, b, b,
    b, b, b, y, b, b, b, b, 
    b, b, b, b, b, b, b, b]

    rotate_1 = rotate_no[x1]
    sense.set_rotation(rotate_1)
    sense.set_pixels(image_pixels_1)

    time.sleep(1)