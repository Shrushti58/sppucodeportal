def avgscore(fds):
    sum=0
    count=0
    for i in range(n):
        if fds[i]!=-1:
            sum=sum+fds[i]
            count=count+1
    avg=sum/count
    return avg

def lowscore(fds):
    for i in range(n):
        if fds[0]!=-1:
            min=fds[0]
            break
    for i in range(n):
        if fds[i]!=-1 and fds[i]<min:
            min=fds[i]
    return min

def highscore(fds):
    max=fds[0]
    for i in range(n):
        if fds[i]>max:
            max=fds[i]
    return max

def absent(fds):
    count=0
    for i in range(n):
        if fds[i]==-1:
            count=count+1
    return count

def maxfeq(fds):
    max=0
    for i in fds:
        feq=fds.count(i)
        if feq>max:
            max=feq
            elem=i
    return elem






n=int(input("Enter total no. of students in class"))
print("Enter marks of fds")
fds=[]
for i in range(n):
    a=int(input())
    fds.append(a)
print(fds)
print("AVg",avgscore(fds))
print("LOW",lowscore(fds))
print("HIGH",highscore(fds))
print("Absent Student",absent(fds))
print("freq",maxfeq(fds))