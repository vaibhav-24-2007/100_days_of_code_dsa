def is_power_of_two(n):
    if n <= 0:
        return False
    if n == 1:
        return True
    if n % 2 != 0:
        return False
    return is_power_of_two(n // 2)

n = int(input())
print(is_power_of_two(n))
