print('Please input your text colours.')
Red1 = int(input('Red value:'))
Green1 = int(input('Green value:'))
Blue1 = int(input('Blue value:'))

print('Please input your background colours.')
Red2 = int(input('Red value:'))
Green2 = int(input('Green value:'))
Blue2 = int(input('Blue value:'))

#scrollspeed
speed=float(input('Please input your scroll speed.'))

#text colour
colour_msg = '({}, {}, {})'.format(Red1,Green1,Blue1)
#back colour
colour_bg = '({}, {}, {})'.format(Red2,Green2,Blue2)

print(colour_msg)

print(colour_bg)
