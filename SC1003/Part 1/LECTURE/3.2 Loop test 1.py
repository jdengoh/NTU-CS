count = 0
number = 9

while number > 0:
    if number % 2 == 0:
        number //2

    elif number % 3 == 0:
        number //3

    else:
        number -=1

    count = count + 1

print ('count is:', count, 'number is:', number)
