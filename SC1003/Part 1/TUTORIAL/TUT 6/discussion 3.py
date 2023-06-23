def reverser(a_str):
    
    if len(a_str) == 1:
        return a_str

    else:
        new_str = reverser(a_str[1:]) + a_str[0]
        
        return new_str

def symmetricString(a_str):
    
    final_string = a_str + reverser(a_str)

    return final_string

print(symmetricString('AbCE'))