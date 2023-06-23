for numbers in range(1,21):

    if numbers%15 == 0:
        print("FizzBuzz")
        continue

    elif numbers%3 == 0:
        print("Fizz")
        continue

    elif numbers%5 == 0:
        print("Buzz")
        continue

    print(numbers)
