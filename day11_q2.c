r=int(input("enter no. of rows: "))
c=int(input("enter no. of columns: "))

a=[]
print("enter matrix elements:")
for i in range(r):
    row=[]
    for j in range(c):
        row.append(int(input()))
    a.append(row)

t=[]
for i in range(c):
    row=[]
    for j in range(r):
        row.append(a[j][i])
    t.append(row)

print("transpose of matrix:")
for i in range(c):
    for j in range(r):
        print(t[i][j],end=" ")
    print()
