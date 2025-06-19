def bubble(mark):
    for i in range(n-1):
        for j in range(n-1):
            if mark[j+1]<mark[j]:
                temp=mark[j+1]
                mark[j+1]=mark[j]
                mark[j]=temp
    return mark

def selection(mark):
    for i in range(n-1):
        for j in range(i+1,n):
            if mark[i]>mark[j]:
                temp=mark[j]
                mark[j]=mark[i]
                mark[i]=temp
    return mark[-5:][::-1]

n=int(input("Enter total no of students"))
print("Enter percentage of student")
mark=[]
for i in range(n):
    a=float(input());
    mark.append(a)
print(mark)
print(selection(mark))

