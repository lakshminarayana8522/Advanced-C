
fruits = ["apple","banana","orange","pineapple","watermelon","mango"]

#using for() and len() methods

print("using for() method...")

for i in range(len(fruits)):
    print(fruits[i])

print("\n")
#using while() and len() methods

print("using while() method...")
i = 0
while i < (len(fruits)):
    print(fruits[i])
    i = i+1

print("\n")
# using list comprehesive mothod

print("using list comprehensive method...")
[print(x) for x in fruits]

