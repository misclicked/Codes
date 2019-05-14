//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll table[10006];

#define MOD 2147483648ll
void build(){
    ll a=1;
    for(int i=0;i<=10005;i++){
        table[i]=a;
        a=(a*2ll)%MOD;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    build();
    string s;
    while(cin>>s){
        reverse(s.begin(),s.end());
        ll ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
                ans+=table[i];
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
}
