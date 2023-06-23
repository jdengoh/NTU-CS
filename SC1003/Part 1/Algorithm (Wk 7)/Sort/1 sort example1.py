from operator import itemgetter

restaurant_info = [['Kentucky', 15, 6, 'Fried Chicken'],
                    ['Macdonald', 12, 5, 'Burger'],
                    ['Subway', 13, 7, 'Sandwiches']]

#[0]: name of restaurant
#[1]: distance
#[2]: price
#[3]: signature dish

sort_info = sorted (restaurant_info, key = itemgetter(1))
print('sort by distance', sort_info)

sort_field = ['name', 'distance', 'price', 'food']

for i in range (len(sort_field)):
    sort_info = sorted(restaurant_info, key = itemgetter(i))
    print('sort by', sort_field[i], sort_info)