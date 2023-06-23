from sense_hat import SenseHat
from sense_hat import SenseHat
sense = SenseHat()

sense.clear()

import random
import time

red = (255,0,0)
yellow = (255,255, 0)
green = (0, 255, 0)
blue = (0, 0, 255)


sense.set_pixel (0, 7, red)
sense.set_pixel (0, 0, green)
sense.set_pixel (7, 0, blue)
sense.set_pixel (7, 7, yellow)

