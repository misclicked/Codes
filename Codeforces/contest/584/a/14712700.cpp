#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll Pow(ll a,ll b)
{
    ll r=1,base=a;
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
    ll a,b;
    cin>>a>>b;
    if((int)log10(b)+1>a)
        cout<<"-1"<<endl;
    else{
        cout<<b;
        for(int i=0;i<a-(int)log10(b)-1;i++)
            cout<<0;
        cout<<endl;
    }
}