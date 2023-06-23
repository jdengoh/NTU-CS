valid_speed = False

while valid_speed != True:
    in_speed = input('Enter the value of the display speed: ')
    
    try:
        float(in_speed)
    except:
        print('Invalid - enter number only')
        continue

    if 0.05>float(in_speed) or 1<float(in_speed):
        print('Invalid - value has to be between 0.05 and 1')
        continue
    else:
        valid_speed = True

else:
    float_speed = float(in_speed)

print(float_speed)
