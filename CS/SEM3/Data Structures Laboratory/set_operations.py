def removedup(lst1):
    lst2=[]
    for i in lst1:
        if i not in lst2:
            lst2.append(i)
    return lst2

def union(lst1,lst2):
    lst3=[]
    for i in lst1:
        lst3.append(i)
    for i in lst2:
        if i not in lst3:
            lst3.append(i)
    return lst3

def intersection(lst1,lst2):
    lst3=[]
    for i in lst1:
        if i in lst2:
            lst3.append(i)
    return lst3

def diff(lst1,lst2):
    lst3=[]
    for i in lst1:
        if i not in lst2:
            lst3.append(i)
    return lst3

def symdiff(lst1,lst2):
    lst3=[]
    lst4=[]
    lst5=[]
    lst3=diff(lst1,lst2)
    lst4=diff(lst2,lst1)
    lst5=union(lst3,lst4)
    return lst5


se=[]
n=int(input("Enter total no. of students in class"))
print("Enter students roll no")
for i in range(n):
    a=int(input())
    se.append(a)
print(se)

foot=[]
n=int(input("Enter total no. students who play football"))
for i in range(n):
    a=int(input())
    foot.append(a)
foot=removedup(foot)

cric=[]
n=int(input("Enter total no. students who play cricket"))
for i in range(n):
    a=int(input())
    cric.append(a)
cric=removedup(cric)

bad=[]
n=int(input("Enter total no. students who play badminton"))
for i in range(n):
    a=int(input()) bad.append(a)
    bad=removedup(bad)

flag=1
while flag==1:
    print("1.Both cricket and Badminton 2.Either cricket or badminton but not both 3.neither cricket nor badminton 4.cricket and football but not badminton")
    ch=int(input("Enter choice"))
    if ch==1:
        cnb=[]
        cnb=intersection(cric,bad)
        print(cnb)
        print("DO you want to continue?")
        c=input("yy/nn")
        if c=='yy':
            flag=1
        else:
            flag=0

    elif ch==2:
        cnb=[]
        cnb=symdiff(cric,bad)
        print(cnb)
        print("DO you want to continue?")
        c=input("yy/nn")
        if c=='yy':
            flag=1
        else:
            flag=0

    elif ch==3:
        cnb=[]
        cnb=union(cric,bad)
        cnb2=diff(se,cnb)
        print(cnb2)
        print("DO you want to continue?")
        c=input("yy/nn")
        if c=='yy':
            flag=1
        else:
            flag=0

    elif ch==4:
        cnb=[]
        cnb=intersection(cric,foot)
        cnb2=diff(cnb,bad)
        print(cnb2)
        print("DO you want to continue?")
        c=input("yy/nn")
        if c=='yy':
            flag=1
        else:
            flag=0

    else:
            print("Enter valid choice")
            flag=0

       

