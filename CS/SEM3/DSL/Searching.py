def linear(stud):
    key=int(input("Enter roll no of student to be searched"))
    for i in stud:
        if i==key:
            return 1
            break
    return -1

def sentinalsearch(stud):
    key=int(input("Enter roll no to be searched"))
    stud.append(key)
    i=0
    while stud[i]!=key:
        i=i+1
    if i!=n:
        return i
    else:
        return -1

def binary(stud):
    key=int(input("Enter roll no to search"))
    low=0
    high=n-1
    while low<high:
        mid=low+high//2
        if stud[mid]==key:
            return mid
        elif key<stud[mid]:
            high=mid-1
        else:
            low=mid+11
    return -1

def fib(stud):
    key=int(input("Enter roll no to be search"))
    a=0
    b=1
    c=a+b
    while(c<n):
        a=b
        b=c
        c=a+b
    offset=-1
    while(c>1):
        i=min(offset+b,n-1)
        if key==stud[i]:
            return i
        elif key>stud[i]:
            c=b
            b=a
            a=c-b
            offset=i  
        else:
            c=a
            b=a-b
            a=c-b
    if b and stud[offset+1]==key:
        return offset+1

    








stud=[]
n=int(input("Enter total number of students"))
print("Enter roll no of students")
for i in range(n):
    a=int(input())
    stud.append(a)
print(stud)
print(fib(stud))

