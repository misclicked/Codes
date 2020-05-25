def d(l,r):
    if l>r:return
    m=(l+r)//2
    a[m]=(l-r,m)
    d(l,m-1)
    d(m+1,r)
for _ in range(int(input())):
    n=int(input())+1
    a=b=[0]*n
    d(1,n-1)
    for i,j in enumerate(sorted(a[1:n])):
    	b[j[1]]=i+1
    print(*b[1:n])