class Qua:
    def __init__(self):
        self.size=int(input("Enter size:"))
        self.hashtable=[None]*self.size
        print(self.hashtable)

    def hashfun(self,key):
        return key%self.size
    def hash2(self,i,key):
        return (self.hashfun(key)+i*i)%self.size

    def insert(self,key):
        index=self.hashfun(key)
        comp=0;
        i=0;
        while(index<self.size and self.hashtable[index]!=None):
            index=self.hash2(i,key)
            comp=comp+1

            if(self.hashtable[index]==None):
                break;
            i=i+1
        self.hashtable[index]=key
        print(self.hashtable)
        print(comp)

    def search(self,key):
        index=self.hashfun(key)
        c=0
        flag=0
        j=0
        while(index<self.size and self.hashtable[index]!=key):
            index=self.hash2(j,key)
            c=c+1
            if(self.hashtable[index]==None):
                break
            if(self.hashtable[index]==key):
                flag=1
                break
            j=j+1
        if(flag==1):
            print("Found at index",index)
        else:
            print("Not")

class double:
    def __init__(self):
        self.size=int(input("Enter size :"))
        self.hashtable=[None]*self.size
        print(self.hashtable)

    def hash1(self,key):
        return key%self.size

    def hash2(self,key):
        return 7-(key%7)

    def insert(self,key):
        i=0;
        comp=0
        index=0
        while(i<self.size):
           index=(self.hash1(key)+(i*(self.hash2(key))))%self.size
           comp=comp+1
           if(self.hashtable[index]==None):
               self.hashtable[index]=key
               print("Inserted at ",index," Comp :",comp)
               break
           else:
               i=i+1
        if(i>=self.size):
            print("Size full")
        print(self.hashtable)

    def search(self,key):
        i=0
        while(i<self.size):
            index=(self.hash1(key)+i*(self.hash2(key))%self.size)
            if(self.hashtable[index]==key):
                print("Key Found at index :",index)
                break
            else:
                i=i+1
        if(i>=self.size):
            return -1
            print("Not found")
        else:
            return index

    def dele(self,key):
        index=self.search(key)
        if(index==-1):
            print("No elle")
        else:
            self.hashtable[index]=None
            print(self.hashtable)

obj=double()
obj.insert(37)
obj.insert(90)
obj.insert(45)
obj.insert(22)




