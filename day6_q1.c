def remove_duplicates(arr):
    if len(arr) == 0:
        return

    k = 0

    for i in range(1, len(arr)):
        if arr[i] != arr[k]:
            k += 1
            arr[k] = arr[i]

    for i in range(k + 1):
        print(arr[i], end=" ")


arr = [1, 1, 2, 2, 3, 4, 4, 5]
remove_duplicates(arr)
