#include<bits/stdc++.h>
#define pi asin(1)*2
using namespace std;
typedef long long ll;
ll input[111111];
ll table[111111];
int main(){
    ll n,tmp;
    ll now=1;
    ll cnt=0;
    cin>>n;
    ll now2=n;
    ll cnt2=0;
    for(ll i=1;i<=n;i++){
        cin>>tmp;
        table[tmp]=i;
    }
    for(ll i=1;i<=n;i++){
        ll j=1;
        while(table[i+j]>table[i+j-1])
            j++;
        i+=j-1;
        cnt=max(cnt,j);
    }
    cout<<n-cnt<<endl;
}