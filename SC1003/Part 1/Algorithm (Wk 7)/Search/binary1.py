# check middle item first
# if not there, is item more or less that middle item
# check half again

def binarysearch(items, target):
#start with entire list
    low = 0
    high = len(items) - 1

#repeatedly subdivide the list in half until target is found
    while low <= high:
        mid = (low+high)//2
        #get the middle item's index

        if items[mid] == target:
            return True
        elif target < items[mid]:
            high = mid-1
        else:
            low = mid+1

    return False

numbers = range(1,20)
print(numbers)
search_key = 7
if binarysearch(numbers, search_key):
    print(search_key, "is in the list")