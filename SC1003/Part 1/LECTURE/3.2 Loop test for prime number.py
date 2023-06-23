n = int(input("What is the number?"))

for number in range(2, int(n/2)+1):
    if n%number == 0:
        text = "no"
        break
else:
    text = "yes"

print(text)
