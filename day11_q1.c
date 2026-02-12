r=int(input("enter no. of rows: "))
c=int(input("enter no. of columns: "))

a=[]
b=[]
sum=[]

print("enter first matrix:")
for i in range(r):
    row=[]
    for j in range(c):
        row.append(int(input()))
    a.append(row)

print("enter second matrix:")
for i in range(r):
    row=[]
    for j in range(c):
        row.append(int(input()))
    b.append(row)

for i in range(r):
    row=[]
    for j in range(c):
        row.append(a[i][j]+b[i][j])
    sum.append(row)

print("sum of matrices:")
for i in range(r):
    for j in range(c):
        print(sum[i][j],end=" ")
    print()
