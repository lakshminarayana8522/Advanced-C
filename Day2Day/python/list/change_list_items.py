# we can also change the values of existing list

fruits = ["apple","banana","mango","orange"]

print(fruits)

fruits[0] = "grapes"

print(fruits)

# we can also update more than one item in list by specifying range

fruits[2:4] = ["pineapple","watermelon"]
print(fruits)

# if we spcify more elements than range, all those extra items are added to the list followed by updated items 

fruits[1:2] = ["cherry","papaya"]
print(fruits)


# we can change the values using insert() method also 

fruits.insert(2,"apple")

print(fruits)


