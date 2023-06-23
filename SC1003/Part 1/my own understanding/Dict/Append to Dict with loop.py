#using loops to form a dictionary with range of rumber

import random

mydict = {}
for x in range (0,41):
    mydict[x] = random.randint(0,100)

print(mydict.items())
print(mydict[2])
