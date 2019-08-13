T = int(input())
money = [1,5,35,50,100,500,1000]
money.reverse()
while T>0:
    inp = int(input())
    ans = 0
    for i in range(len(money)):
        ans += int(inp/money[i])
        inp = inp%money[i]
    print(ans)
    T-=1

