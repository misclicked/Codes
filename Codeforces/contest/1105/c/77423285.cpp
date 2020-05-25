#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007ll
ll a,b,c,na,nb,nc;
ll ta,tb,tc;
ll n,l,r;
int main(){
    cin>>n>>l>>r;
    na=nb=nc=ceill((r-l+1)/3.0)-1;
    ll ln=l%3,rn=r%3;
    if(rn<ln)rn+=3;
    for(int i=ln;i<=rn;i++){
        if(i%3==2)nc++;
        else if(i%3==1)nb++;
        else na++;
    }
    a=na,b=nb,c=nc;
    //cout<<na<<" "<<nb<<" "<<nc<<endl;
    for(int i=1;i<n;i++){
        ta=(a*na%mod+b*nc%mod+c*nb%mod)%mod;
        tb=(a*nb%mod+b*na%mod+c*nc%mod)%mod;
        tc=(a*nc%mod+b*nb%mod+c*na%mod)%mod;
        a=ta;b=tb;c=tc;
        //cout<<a<<" "<<b<<" "<<c<<endl;
    }
    cout<<a%mod<<endl;
}