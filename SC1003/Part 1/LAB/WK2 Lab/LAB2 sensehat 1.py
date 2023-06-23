from sense_hat import SenseHat
sense = SenseHat()

sense.set_rotation(90)

sense.show_message("Hello", text_colour=(225,225,0), back_colour = (0,225,225), scroll_speed=0.05)

sense.clear(0, 0, 0)