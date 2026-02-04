n = int(input("enter size of array: "))

arr = []
for i in range(n):
    arr.append(int(input("enter element: ")))

k = int(input("enter key k: "))

comp = 0
pos = -1

for i in range(n):
    comp = comp + 1
    if arr[i] == k:
        pos = i + 1   # pos. starting from 1
        break

if pos != -1:
    print("key found at pos.:", pos)
else:
    print("key not found")

print("no. of comparisons:", comp)
