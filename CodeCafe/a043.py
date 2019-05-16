from random import shuffle
n=int(input())
lst=list(range(1,n+1))
shuffle(lst)
print(*lst)