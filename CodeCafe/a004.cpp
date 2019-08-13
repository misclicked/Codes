//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T;
    cin>>T;
    while(T--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans=0;
        ans+=ceil(c/2.0)*a;
        ans-=(c/2)*b;
        cout<<ans<<endl;
    }
}
