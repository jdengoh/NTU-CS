from sense_hat import SenseHat
from sense_hat import SenseHat
sense = SenseHat()
import random
import time

rotate_no = [0, 90, 180, 270]

while True:
  
    x1 = random.randint(0,3)
    x2 = random.randint(0,3)

    r1 = random.randint(0,255)
    g1 = random.randint(0,255)
    b1 = random.randint(0,255)

    r2 = random.randint(0,255)
    g2 = random.randint(0,255)
    b2 = random.randint(0,255)

    r3 = random.randint(0,255)
    g3 = random.randint(0,255)
    b3 = random.randint(0,255)

    r4 = random.randint(0,255)
    g4 = random.randint(0,255)
    b4 = random.randint(0,255)

    b= (r1, g1, b1)
    y= (r2, g2, b2)
    i= (r3, g3, b3)
    j= (r4, g4, b4)

    image_pixels_1 =	[b, b, b, b, b, b, b, b,
    b, b, b, y, b, b, b, b,
    b, b, y, y, y, b, b, b,
    b, y, b, y, b, y, b, b,
    b, b, b, y, b, b, b, b,
    b, b, b, y, b, b, b, b,
    b, b, b, y, b, b, b, b, 
    b, b, b, b, b, b, b, b]

    image_pixels_2 =	[i, i, i, i, i, i, i, i,
    i, i, i, j, i, i, i, i,
    i, i, j, j, j, i, i, i,
    i, j, i, j, i, j, i, i,
    i, i, i, j, i, i, i, i,
    i, i, i, j, i, i, i, i,
    i, i, i, j, i, i, i, i, 
    i, i, i, i, i, i, i, i]

    rotate_1 = rotate_no[x1]
    rotate_2 = rotate_no[x2]

    sense.set_rotation(rotate_1)
    sense.set_pixels(image_pixels_1)

    time.sleep(1)

    sense.set_rotation(rotate_2)
    sense.set_pixels(image_pixels_2)

    time.sleep(1)
