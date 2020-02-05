//
// Created by misclicked on 2019/9/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll table[1005][1005];

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
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>table[i][j];
        }
    }
    vector<ll> ans;
    for(int i=0;i<n;i++){
        ans.push_back(sqrtl(table[i][(i+1)%n]*table[i][(i+2)%n]/table[(i+1)%n][(i+2)%n]));
    }
    cout<<ans[0];
    for(int i=1;i<n;i++){
        cout<<" "<<ans[i];
    }
    cout<<endl;
}