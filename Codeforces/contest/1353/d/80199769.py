a=[(0,0)]*200001
b=[0]*200001
def d(l,r):
    if l>r:return
    m=(l+r)//2
    a[m]=(l-r,m)
    d(l,m-1)
    d(m+1,r)
for _ in range(int(input())):
    n=int(input())
    d(1,n)
    c=1
    for i in sorted(a[1:n+1],key=lambda g:g[0]):
        b[i[1]]=c
        c+=1
    print(*b[1:n+1])
