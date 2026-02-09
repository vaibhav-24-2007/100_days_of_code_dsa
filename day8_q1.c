def power(a, b):
    if b == 0:
        return 1
    return a * power(a, b - 1)

a = int(input("enter a: "))
b = int(input("enter b: "))

result = power(a, b)
print(result)
