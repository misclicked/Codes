//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int table[CHAR_MAX];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    string s;
    cin>>s;
    int ans=0;
    for(auto it:s){
        table[it]++;
        ans=max(ans,table[it]);
    }
    cout<<s.size()-ans<<endl;
}
