foodlist = ['burger', 'chicken', 'drink']

# method1
for item in foodlist:
    if item == 'chicken':
        print('Yes')
        break

# method2 -> index method

ind = foodlist.index('chicekn')
print(ind)