def merge_logs(log1, log2):
    i = 0
    j = 0
    merged = []

    while i < len(log1) and j < len(log2):
        if log1[i] <= log2[j]:
            merged.append(log1[i])
            i += 1
        else:
            merged.append(log2[j])
            j += 1

    while i < len(log1):
        merged.append(log1[i])
        i += 1

    while j < len(log2):
        merged.append(log2[j])
        j += 1

    return merged


log1 = [1, 4, 6, 10]
log2 = [2, 3, 7, 8, 12]
print(merge_logs(log1, log2))
