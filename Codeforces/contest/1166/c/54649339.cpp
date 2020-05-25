//
// Created by misclicked on 2019/5/26.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> vec;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n;
    cin>>n;
    vec.resize(n);
    for(auto &it:vec){
        cin>>it;
        it=abs(it);
    }
    sort(vec.begin(),vec.end());
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        int now=ceil(vec[i]/2.0);
        int idx=lower_bound(vec.begin(),vec.end(),now)-vec.begin();
        ans+=(i-idx);
        //cout<<vec[i]<<" "<<now<<" "<<idx<<endl;
    }
    cout<<ans<<endl;
}
