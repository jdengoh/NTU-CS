from unittest.mock import NonCallableMagicMock


def binary_search(items, target, low=0, high = None):
    #when recurring, while reassign high value
    if high == None:
        high = len(items) -1

    if low>high:
        return False
    
    mid = (low+high)//2

    if target == items[mid]:
        return True
    elif target>items[mid]:
        #seach "right" side
        return binary_search(items, target, low = (mid+1), high = high)
    else:
        #search "left" side
        return binary_search(items, target, low = low, high = mid-1)

numbers = range(1,50)
search_key = 34

if binary_search(numbers, search_key, 0):
    print(search_key, "is in the list")