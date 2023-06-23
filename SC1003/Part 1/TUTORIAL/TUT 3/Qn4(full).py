
import random
#assume 20 student in both classes

#generating random scores for 20 people
class1grades = list(random.randint(0,100) for i in range (1,21))
print("Class 1 scores are: ", class1grades)


class2grades = list(random.randint(0,100) for i in range(1,21))
print("Class 2 scores are: ", class2grades)

class1average = sum(class1grades)/len(class1grades)
print("Class 1 average score is: ", class1average)


class2average = sum(class2grades)/len(class2grades)
print("Class 2 average score is: ", class2average)

#comparing average
if class1average < class2average:
    print("Class 2 average is higher than Class 1.")
    
elif class1average == class2average:
    print("Both classes have the same average.")
        
else:
    print("Class 1 average is higher than Class 2.")




class1grades.sort()
class1grades
#largest number will be at the end
print("Class 1 highest score is: ", class1grades[-1])

class2grades.sort()
class2grades
#largest number will be at the end
print("Class 2 highest score is: ", class2grades[-1])

#comparing highest score

if class1grades[-1] < class2grades[-1]:
    print("Class 2 has the highest score.")
    
elif class1grades[-1] == class2grades[-1]:
    print("Both classes have the same highest score.")
        
else:
    print("Class 1 has the highest score")


