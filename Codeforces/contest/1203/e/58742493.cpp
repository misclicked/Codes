//
// Created by misclicked on 2019/8/13.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int,int> mape;

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
        int data;
        cin>>data;
        mape[data]++;
    }
    int ans=0;
    for(int i=1;i<=150005;i++){
        if(mape[i-1]){
            mape[i-1]--;
            ans++;
        }else if(mape[i]){
            mape[i]--;
            ans++;
        }else if(mape[i+1]){
            mape[i+1]--;
            ans++;
        }
    }
    cout<<ans<<endl;
}