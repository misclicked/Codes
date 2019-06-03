//
// Created by misclicked on 2019/6/2.
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
    ll n,m;
    cin>>n>>m;
    cout<<m;
    for(int i=1;i<n;i++){
        cout<<" 0";
    }
    cout<<endl;
}
