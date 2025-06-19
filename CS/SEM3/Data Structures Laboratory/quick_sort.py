def partition(mark,low,high):
    pivot=mark[low]
    i=low+1
    j=high
    while True:
        while i<=j and mark[i]<=pivot:
            i=i+1
        while i<=j and mark[j]>=pivot:
            j=j-1
        if i<=j:
            mark[i],mark[j]=mark[j],mark[i]
        else:
            break
    mark[low],mark[j]=mark[j],mark[low]
    return j

def quick(mark,low,high):
    while low<high:
        p=partition(mark,low,high)
        quick(mark,low,p-1)
        quick(mark,p+1,high)
        return mark[-5:][::-1]
        
            
n=int(input("Enter total no of students"))
print("Enter percentage of student")
mark=[]
for i in range(n):
    a=float(input());
    mark.append(a)
print(mark)
print(quick(mark,0,n-1))