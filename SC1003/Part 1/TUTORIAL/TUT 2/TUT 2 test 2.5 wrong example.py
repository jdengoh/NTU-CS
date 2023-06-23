#without break, it will count every signgle a in the string

str = input("enter a string (enter #### to stop):")

count = 0

while str != "####":
    for letter in str:
        if letter == 'a':
            break
        count += 1
        
    str = input("enter a string (enter #### to stop):")

print(count, "strings with letter 'a'")
