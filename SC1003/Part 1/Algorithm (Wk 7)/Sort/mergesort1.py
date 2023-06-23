def mergesort(list_of_items):
    list_len = len(list_of_items)

    #base case
    if list_len <2:
        return list_of_items
    
    left_list = list_of_items[:list_len//2]
    right_list =list_of_items[list_len//2:]
    
    #merge sort let and right list recursvively
    left_list = mergesort(left_list)
    right_list = mergesort(right_list)

    return merge(left_list, right_list)
    
def merge (left_list, right_list):
    
    result_list = []

    #while left and right list has elements
    while left_list and right_list:
        if left_list[0] < right_list[0]:
            result_list.append(left_list[0])
            left_list.pop(0)
        else:
            result_list.append(right_list[0])
            right_list.pop(0)

    #left list still contain element, so append its content to end of results
    if left_list:
        result_list.extend(left_list)
    else:
        #right list is the one with an element left, so append to end of results
        result_list.extend(right_list)
    
    return result_list

trial_1 = [2,43,23,5,96,3,25,40]

print(mergesort(trial_1))