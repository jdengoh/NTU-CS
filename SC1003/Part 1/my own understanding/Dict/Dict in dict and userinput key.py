# for 2 Classes, FE and AG, 40 students, grades(just use random)
#idea is to assign class as key, value as dictionary of (reg no., score)
import random
classFE_grades = [random.randint(0,100) for x in range(1,41) ]
classAG_grades = [random.randint(0,100) for y in range(1,41)]

classFE_reg = [x for x in range(0,41)]
classAG_reg = [y for y in range(0,41)]

newzipFE = zip(classFE_reg, classFE_grades)
newzipAG = zip(classAG_reg, classAG_grades)

FE_dict = dict(newzipFE)
AG_dict = dict(newzipAG)

class_dict = {}
class_dict['FE'] = FE_dict
class_dict['AG'] = AG_dict

#print(class_dict.items())
#print(class_dict['FE'][5])
no_input = 0

while no_input !='####':
    print('Enter the class(all caps) and the register number.')

    try:
        class_input = str(input('Enter the class.'))
        if class_input == '####':

            no_input = class_input
            continue

        student_input = int(input('Enter the student register number.'))

        print(class_dict[class_input][student_input])

    except:
        print('ERROR. Please input again.')
        continue