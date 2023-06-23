from sense_hat import SenseHat
from sense_hat import SenseHat
sense = SenseHat()
import random
import time

y = (255, 255, 0)
b = (0, 0, 0)
image_pixels_1 =	[b, b, b, b, b, b, b, b,
b, b, b, y, b, b, b, b,
b, b, y, y, y, b, b, b,
b, y, b, y, b, y, b, b,
b, b, b, y, b, b, b, b,
b, b, b, y, b, b, b, b,
b, b, b, y, b, b, b, b, 
b, b, b, b, b, b, b, b]


image_pixels_2 =	[y, y, y, y, y, y, y, y,
y, y, y, b, y, y, y, y,
y, y, b, b, b, y, y, y,
y, b, y, b, y, b, y, y,
y, y, y, b, y, y, y, y,
y, y, y, b, y, y, y, y,
y, y, y, b, y, y, y, y, 
y, y, y, y, y, y, y, y]

rotate_no = [0, 90, 180, 270]


while True:
  
  x = random.randint(0,3)
  y = random.randint(0,3)
  
  rotate_1 = rotate_no[x]
  rotate_2 = rotate_no[y]
  
  sense.set_rotation(rotate_1)
  sense.set_pixels(image_pixels_1)
  
  time.sleep(1)
  
  sense.set_rotation(rotate_2)
  sense.set_pixels(image_pixels_2)
  
  time.sleep(1)
  