//
// Created by misclicked on 2019/5/7.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<int,int> mape;
vector<int> vec;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,m,data;
    ll A,B;
    A=B=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        A+=data;
        vec.push_back(data);
    }
    sort(vec.begin(),vec.end());
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>data;
        B+=data;
        mape[data]++;
    }
    int diff=A-B;
    for(auto it:vec){
        if(mape.count((diff-it)*-1)){
            cout<<A-it<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
