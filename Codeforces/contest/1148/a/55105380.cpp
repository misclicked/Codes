//
// Created by misclicked on 2019/6/5.
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
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<c*2+min(a,b)*2+((max(a,b)-min(a,b))?1:0)<<endl;
}
