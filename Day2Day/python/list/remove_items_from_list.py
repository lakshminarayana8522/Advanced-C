fruits = ["apple","banana","pineapple","papaya","watermelon","orange"]

print("before removing...using remove() method")
print(fruits)

# removing banana item from the list using remove() method 

fruits.remove("banana")

print("after removing an item from the list using remove() method")
print(fruits)

#using pop() method we can remove element by index number. if we did not 
# specify the index number it will remove element at last.

print("using pop() method...deleting item at index 2");
fruits.pop(2)
print(fruits)


#using del method we can also delete item in the list by index method
# syntax: del fruits[0]

print("using del method to remove item from the list..3")
del fruits[3]
print(fruits)

# we can also delete total list using del method
# syntax: del fruits


#using clear() method we can delete the all items in the list. but list is stil
# exits only items will removed.

#syntax: fruits.clear()

print("using clear method..");
fruits.clear()
print(fruits)




