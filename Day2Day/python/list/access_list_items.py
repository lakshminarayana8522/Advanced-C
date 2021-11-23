#Accessing list items


#we can access list items by index method. the index is start from 0;

fruits = ["apple","banana","mango","grapes","orange",]

print(fruits[0]);
print(fruits[1]);


# we can also access items in list by specifying range


print(fruits[1:3]);


# we can also access list items using negative indexes also

print(fruits[-1])
print(fruits[-3])


print(fruits[-4:-1])


# we can also check for element in list using in operator

if "mango" in fruits:
    print("mango is present in this list")

