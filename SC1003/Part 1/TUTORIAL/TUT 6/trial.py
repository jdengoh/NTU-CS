trial = 'abcDefg'

str_list =[]

str_list = [i for i in trial]

#SLOWER METHOD BELOW

#for i in range(len(trial)):
#    str_list.append(trial[i])


str_list[0] = str_list[0].upper()

print(str_list)

new_str = ''.join(str_list)
print(new_str)

print('1234;;'.upper())