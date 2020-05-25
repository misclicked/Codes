#include<iostream>
#include<climits>
#include<cstring>
#define MIN(a,b) a<b?a:b
using namespace std;
typedef long long LL;
LL dp[31];
LL pow4(int a,int b)
{
    LL r=1,base=a;
    while(b!=0)
    {
        if(b&1)
            r*=base;
        base*=base;
        b>>=1;
    }
    return r;
}
int main(){
    for(int i=0;i<=30;i++)
        dp[i]=pow4(2,i);
    int n;
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int i=0;
        LL ans=0;
        while(n>=dp[i]){
            ans-=dp[i];
            if(n<dp[i+1])
                ans+=(dp[i]+1+n)*(n-dp[i])/2;
            else
                ans+=(dp[i]+dp[i+1])*(dp[i+1]-1-dp[i])/2;
            i++;
        }
        cout<<ans<<endl;
    }
    
} 
