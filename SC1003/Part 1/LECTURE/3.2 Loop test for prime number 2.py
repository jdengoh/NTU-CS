print("Check if the number is prime or not!\nEnter your number, or enter 'stop' to halt the programme.")

n_string = input("What is the number?")

while n_string != "stop":

    n=int(n_string)

    for number in range(2, int(n/2)+1):
        if n%number == 0:
            isprime = "no"
            break

    else:
        isprime = "yes"

    print(isprime)
    
    n_string = input("What is the number?")
