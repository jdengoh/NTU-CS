for numbers in range (1,21):

    if numbers%15 == 0:
        print("Fizzbuzz")

    elif numbers%5 == 0:
        print("Buzz")

    elif numbers%3 == 0:
        print("Fizz")

    else:
        print(numbers)
