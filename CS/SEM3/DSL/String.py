def word_long(str):
    word=str.split()
    l=0
    long=''
    for i in word:
        if len(i)>l:
            l=len(i)
            long=i
    return long

def feq_occ(str):
    c=input("Enter char")
    count=0
    for i in str:
        if i==c:
            count=count+1
    return count

def pali(str):
    str1=str.replace(" ","")
    rev=str1[::-1]
    if str1==rev:
        print("Palidrome")
    else:
        print("NOt")

def first_occ(str,sub):
    word=str.split()
    for i in word:
        if i==sub:
            return str.index(i)
    return -1

def occ_word(str):
    count={}
    word=str.split()
    for i in word:
        if i in count:
            count[i]+=1
        else:
            count[i]=1
    return count

str=input("Enter string")
"""print(str)
print(word_long(str))
print("FEQ",feq_occ(str))
print("First occ",first_occ(str,'wel'))"""
print(occ_word(str))
