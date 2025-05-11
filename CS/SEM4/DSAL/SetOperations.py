class setadt:
    def __init__(self):
        self.list1=[]
        self.set1=set(self.list1)


    def insert(self):
        a=int(input("Enter Element to insert :"))
        if(a in self.set1):
            print("Set dont allow duplicates..")
        else:
            self.set1.add(a)
        print(self.set1)

    def deleteele(self):
        a=int(input("Enter Element to be delted :"))
        if(a in self.set1):
            self.set1.remove(a)
        else:
            print("Not Found")
        print(self.set1)

    def search(self):
        a=int(input("Enter Element to be search"))
        v=False
        l=list(self.set1)
        for i in range(len(l)):
            if l[i]==a:
                v=True
                break
        if v:
            print("Found",i)
        else:
            print("Not")
        self.set1=set(l)

    def sizeofset(self):
        print("Size of Set is ",len(self.set1))

    def unionofset(self):
        l=[]
        set2=set(l)
        n=int(input("Enter no of Elemnts in set2 "))
        for i in range(n):
            a=int(input("Enter"))
            set2.add(a)
            print(set2)
        u=[]
        for i in self.set1:
            u.append(i)

        for i in set2:
            if i not in u:
                u.append(i)

        print(set(u))

    def inter(self):
        l=[]
        set2=set(l)
        n=int(input("Enter no of Elemnts in set2 "))
        for i in range(n):
            a=int(input("Enter"))
            set2.add(a)
            print(set2)
        u=[]
        for i in self.set1:
            if i in set2:
                u.append(i)
        print(set(u))

    def diff(self):
        l=[]
        set2=set(l)
        n=int(input("Enter no of Elemnts in set2 "))
        for i in range(n):
            a=int(input("Enter"))
            set2.add(a)
            print(set2)
        u=[]
        for i in self.set1:
            if i not in set2:
                u.append(i)
        print(set(u))

obj=setadt()
obj.insert()
obj.insert()
obj.insert()
obj.insert()


