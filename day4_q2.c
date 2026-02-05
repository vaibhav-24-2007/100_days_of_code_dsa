n = int(input("enter n: "))

nums = []
for i in range(n):
    x = int(input())
    nums.append(x)

val = int(input("enter val: "))

k = 0   # pointer for elements not equal to val

for i in range(n):
    if nums[i] != val:
        nums[k] = nums[i]
        k = k + 1

print("count:", k)
print("updated array:", nums[:k])
