//
// Created by misclicked on 2019/5/15.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> input[10005];
vector<int> ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,m;
    bool flag=false;
    while(cin>>n){
        if(flag)cout<<endl;
        flag=true;
        int maxi=0;
        for(int i=0;i<n;i++){
            cin>>m;
            input[i].resize(m);
            for(auto &it:input[i]){
                cin>>it;
            }
            maxi=max(maxi,m);
        }
        ans.clear();
        for(int i=0;i<maxi;i++){
            for(int j=0;j<n;j++){
                if(i<input[j].size()){
                    ans.push_back(input[j][i]);
                }
            }
        }
        int here=ans[0];
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            if(ans[i]!=here){
                cout<<" "<<ans[i];
                here=ans[i];
            }
        }
        cout<<endl;
        return 0;
    }
}
