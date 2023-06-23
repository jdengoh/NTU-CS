width = int(input("Please enter the pattern width: "))

for i in range (width+1):

    for j in range(i):

        print("*", end="")

    print()

for i in range (width-1,0, -1):

    for j in range(i):

        print("*", end="")

    print()
