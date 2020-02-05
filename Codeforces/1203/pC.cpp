//
// Created by misclicked on 2019/8/13.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a,ll b){
    if(b==0)return a;
    a%=b;
    return gcd(b,a);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    ll n;
    cin>>n;
    ll now;
    cin>>now;
    for(int i=1;i<n;i++){
        ll data;
        cin>>data;
        now=__gcd(now,data);
    }
    ll cnt=1;
    ll tmp;
    ll Now=now;
    for(ll i=2;i<=now;i++){
        //cout<<now<<endl;
        if(now%i==0){
            tmp=0;
            while(now%i==0){
                now/=i;
                tmp++;
            }
            cnt*=tmp+1;
        }
    }
    cout<<cnt<<endl;
}
