import math
radiusString = input("Enter the radius of your circle.")
radiusFloat = float(radiusString)
circumfrance = 2 * math.pi * radiusFloat
area = math.pi * radiusFloat * radiusFloat

print() # print a line break
print ("the circumfrance of your circle is:",circumfrance,\
       ", and the area is:",area)
