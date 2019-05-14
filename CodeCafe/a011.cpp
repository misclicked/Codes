//
// Created by misclicked on 2019/5/7.
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
    int n,m;
    cin>>n>>m;
    ll ans=0;
    ll data,sum=0;
    for(int i=0;i<n;i++){
        cin>>data;
        vec.push_back(data);
    }
    for(int i=2;i<n;i++){
        int now=vec[i-2];
        int use=ceil((now*1.0)/m);
        int remain=use*m-now;
        vec[i-1]=max(0,vec[i-1]-remain);
        ans+=use;
    }
    ans+=ceil(((vec[n-1]+vec[n-2])*1.0)/m);
    cout<<ans<<endl;
}
