from sense_hat import SenseHat
from sense_hat import SenseHat
sense = SenseHat()

#user inputs
print('Please input your text colours.')
Red1 = int(input('Red value:'))
Green1 = int(input('Green value:'))
Blue1 = int(input('Blue value:'))

text_input = (Red1, Green1, Blue1)

print('Please input your background colours.')
Red2 = int(input('Red value:'))
Green2 = int(input('Green value:'))
Blue2 = int(input('Blue value:'))

back_input = (Red2, Green2, Blue2)

#scrollspeed
speed=float(input('Please input your scroll speed.'))

sense.set_rotation(180)

sense.show_message("Hello", text_colour = text_input,
                            back_colour = back_input,
                            scroll_speed=speed)
sense.clear(0, 0, 0)
