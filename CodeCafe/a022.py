import sys
sys.setrecursionlimit(10000000)
T = int(input())
money = [1,5,35,50,100,500,1000]
money.reverse()
dp = {}
for m in money:
    dp[m] = 1
Inf = 1e30
def calc(n):
    if(n<0):
        return Inf
    if(dp.__contains__(n)):
        return dp[n]
    ans = Inf
    for m in money:
        ans = min(calc(n-m)+1,ans)
    if ans != Inf:
        dp[n] = ans
    return ans

while T>0:
    inp = int(input())
    calc(inp)
    print(dp[inp])
    T-=1
