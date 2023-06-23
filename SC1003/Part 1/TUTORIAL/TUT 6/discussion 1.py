
def reverseAndRepeat (my_str, num):
    int_num = int(num)

    if len(my_str) == 1:
        return int(int_num)*my_str

    else:
        new_str = reverseAndRepeat(my_str[1:], num) + int(int_num)*my_str[0]
        
        return new_str

str_input = input('my_str:')
num_input = (input('How many repeats?' ))

print( reverseAndRepeat (str_input, num_input) )