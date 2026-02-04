n = int(input("enter value of n: "))

arr = []
for i in range(n - 1):
    arr.append(int(input("enter element: ")))

exp_sum = n * (n + 1) // 2   # sum of 1 to n
act_sum = 0

for i in arr:
    act_sum = act_sum + i

miss = exp_sum - act_sum

print("missing element is:", miss)
