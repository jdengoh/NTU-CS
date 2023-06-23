casesPassed = 0
check = {
    'number': '.*[0-9]',
    'lowercase': '.*[a-z]',
    'uppercase': '.*[A-Z]',
    'special': '.*[!@#$%^&*]',
}


print(check.items())
print(check['number'])

squareno = [i**2 for i in range(1,101) if i**2%3==0]
print(squareno)