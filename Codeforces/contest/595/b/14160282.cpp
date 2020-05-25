#include<bits/stdc++.h>
#include<string>
using namespace std;
long long p[11]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
long long up(long long a,long long b){
    long long ans=a/b;
    if(a*1.0/b>a/b)
        ans+=1;
    return ans;
}
int main(){
    int a[111111];
    int b[111111];
    long long n,k,cnt;
    long long a1;
    long long ans=1;
    string s;
    cin>>n>>k;
    for(long long i=0;i<n/k;i++)
        cin>>a[i];
    for(long long i=0;i<n/k;i++)
        cin>>b[i];
     for(long long i=0;i<n/k;i++){
        a1=(p[k]-1)/a[i]+1;
        a1-=((b[i]+1)*p[k-1]-1)/a[i]-up(b[i]*p[k-1],a[i]);
        a1-=1;
        /*for(long long j=b[i]*p[k-1];j<(b[i]+1)*p[k-1];j++)
            if(j%a[i]==0)
                a1--;*/
        ans=(ans*a1)%1000000007;
    }
    cout<<ans<<endl;
} 