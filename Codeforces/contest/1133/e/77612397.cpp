#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5005;
int a[maxn],l[maxn];
int dp[maxn][maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    dp[0][0]=0;
    for(int i=1;i<=n;i++) l[i]=lower_bound(a+1,a+1+n,a[i]-5)-a;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(dp[i][j],dp[l[i]-1][j-1]+i-l[i]+1);
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}