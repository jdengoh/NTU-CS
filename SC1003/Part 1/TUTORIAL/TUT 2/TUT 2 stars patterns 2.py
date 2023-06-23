width = int(input("Please enter pattern width: "))

for stars in range (1, (width+1) ):
       print("*" * stars)

for stars in range ( (width-1), 0, -1):
    print("*" * stars)
