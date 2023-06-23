str = input("enter a string (enter #### to stop):")

count = 0

while str != "####":
    for letter in str:
        if letter == 'a':
            count += 1
            break
        else:
            pass
                
    str = input("enter a string (enter #### to stop):")

print(count, "strings with letter 'a'")
