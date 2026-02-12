n=int(input("enter no. of rows: "))
m=int(input("enter no. of columns: "))

a=[]
print("enter matrix elements:")
for i in range(n):
    row=[]
    for j in range(m):
        row.append(int(input()))
    a.append(row)

if n!=m:
    print("matrix is not symmetric")
else:
    flag=1
    for i in range(n):
        for j in range(m):
            if a[i][j]!=a[j][i]:
                flag=0
                break
        if flag==0:
            break

    if flag==1:
        print("matrix is symmetric")
    else:
        print("matrix is not symmetric")
