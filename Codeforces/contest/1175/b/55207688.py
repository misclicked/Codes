import atexit
import io
import sys

_I_B = sys.stdin.read().splitlines()
input = iter(_I_B).__next__
_O_B = io.StringIO()
sys.stdout = _O_B

@atexit.register
def write():
    sys.__stdout__.write(_O_B.getvalue())

T = int(input())
stk = [None]*100005
stk[0]=1
top=0
ans=0
for turn in range(T):
    inp = input().split()
    if inp[0]=="add":
        ans+=stk[top]
    if inp[0]=='for':
        stk[top+1] = stk[top]*int(inp[1])
        if stk[top+1] > 2**33:
            stk[top+1] = 2**33
        top+=1
    if inp[0]=='end':
        top-=1
if ans > 2**32-1:
    print('OVERFLOW!!!')
else:
    print(ans)