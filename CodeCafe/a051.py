n=int(input())
lst=[]
for i in range(n):
    n=tuple(map(int,input().split()))
    lst.append(n)
lst.sort()
print(*(list(zip(*lst))[1]))