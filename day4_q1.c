n = int(input("enter n: "))

arr = []
for i in range(n):
    val = int(input())
    arr.append(val)

left = 0
right = n - 1

while left < right:
    temp = arr[left]
    arr[left] = arr[right]
    arr[right] = temp

    left = left + 1
    right = right - 1

print("reversed array:", arr)
