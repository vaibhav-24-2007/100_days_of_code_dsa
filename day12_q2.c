r=int(input("enter no. of rows: "))
c=int(input("enter no. of columns: "))

a=[]
print("enter matrix elements:")
for i in range(r):
    row=[]
    for j in range(c):
        row.append(int(input()))
    a.append(row)

flag=1

for i in range(r-1):
    for j in range(c-1):
        if a[i][j]!=a[i+1][j+1]:
            flag=0
            break
    if flag==0:
        break

if flag==1:
    print("true")
else:
    print("false")
