/*

求一个区间回文数的个数


*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<map>

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

#define bug printf("hihi\n")

#define eps 1e-12

typedef long long ll;

using namespace std;
#define N 20

ll dp[20][N];
int bit[N];
int a[N];

ll dfs(int pos,int len,bool bound)
{
    if(pos==-1) return 1;
    if(len&&!bound&&dp[len][pos]!=-1) return dp[len][pos];
    int up=bound ? bit[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {
        if(len==0)
        {
            a[pos]=i;
            ans+=dfs(pos-1,i ? pos:0,bound&&i==up);
        }
        else
        {
            int t=(len+1)>>1;
            bool ha=(len&1) ? pos>=t:pos>=t;
            if(ha)
            {
                a[pos]=i;
                ans+=dfs(pos-1,len,bound&&i==up);
            }
            else
            {
                a[pos]=i;
                if(a[len-pos]==i)
                    ans+=dfs(pos-1,len,bound&&i==up);
            }
        }
    }
    if(!bound&&len) dp[len][pos]=ans;
    return ans;
}

ll solve(ll a)
{
    if(a<0) return 0;
    if(a==0) return 1;
    int i,j;
    int len=0;
    while(a)
    {
       bit[len++]=a%10;
       a/=10;
    }
    return dfs(len-1,0,true);
}

int main()
{
    int i,j,t,ca=0;
    ll a,b;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a>b) swap(a,b);
        a=solve(a-1);
        b=solve(b);
        printf("Case %d: %lld\n",++ca,b-a);
    }
    return 0;
}
