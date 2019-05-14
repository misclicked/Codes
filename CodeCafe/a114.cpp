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
    int n;
    while(cin>>n){
        ll ans=LLONG_MIN,data,ans2=LLONG_MIN;
        while(n--){
            cin>>data;
            if(data>=0){
                if(ans==LLONG_MIN)ans=0;
                ans+=data;
            }
            else ans2=max(ans2,data);
        }
        if(ans==LLONG_MIN)cout<<ans2<<endl;
        else cout<<ans<<endl;
    }
}
