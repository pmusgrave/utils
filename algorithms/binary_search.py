import math
random_data = []
dataset_size = 1001
i = 0
while i <= dataset_size:
    random_data.append(i)
    i += 1

def binary_search(data, key):
    min_index = 0
    max_index = len(data)
    found_index = None
    while (max_index - min_index) > 1:
        if key == data[min_index]:
            found_index = min_index
            break

        if (max_index - min_index) == 2:
            search_index = min_index + 1
        else:
            search_index = math.floor( (max_index-min_index) / 2 ) + min_index

        print (search_index)

        if key == data[search_index]:
            found_index = search_index
            break
        elif key < data[search_index]:
            max_index = search_index
        elif key > data[search_index]:
            min_index = search_index
    return found_index

key = int(input("Enter integer search value between 0 and " + str(dataset_size-1) + ': '))
index = binary_search(random_data, key)
if index != None:
    print ("Value is located at index", index)
else:
    print("Value not found")
