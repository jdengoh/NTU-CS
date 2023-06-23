def reverser(a_str):
    
    if len(a_str) == 1:
        return a_str

    else:
        new_str = reverser(a_str[1:]) + a_str[0]
        
        return new_str


print(reverser('hello'))
