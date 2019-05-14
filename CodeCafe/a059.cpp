//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    ans.push_back({bx+cx-ax,by+cy-ay});
    ans.push_back({ax+bx-cx,ay+by-cy});
    ans.push_back({ax+cx-bx,ay+cy-by});
    sort(ans.begin(),ans.end());
    for(int i=0;i<3;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
