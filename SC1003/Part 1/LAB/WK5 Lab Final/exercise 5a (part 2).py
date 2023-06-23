from sense_hat import SenseHat
from sense_hat import SenseHat
sense = SenseHat()

import random
import time

sense.clear()

red = (255,0,0)
yellow = (255,255, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

while True:
  x1 = random.randint(0,7)
  y1 = random.randint(0,7)
  x2 = random.randint(0,7)
  y2 = random.randint(0,7)
  x3 = random.randint(0,7)
  y3 = random.randint(0,7)
  x4 = random.randint(0,7)
  y4 = random.randint(0,7)

  sense.set_pixel (x1, y1, red)
  sense.set_pixel (x2, y2, green)
  sense.set_pixel (x3, y3, blue)
  sense.set_pixel (x4, y4, yellow)
    
  time.sleep(1)
  
  sense.clear()