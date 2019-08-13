//
// Created by misclicked on 2019/6/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool visited[(1<<18)+5]={0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,x;
    cin>>n>>x;
    vector<int> vec;
    vec.push_back(0);
    visited[0]=1;
    for(int i=1;i<(1<<n);i++){
        if(visited[i^x])continue;
        vec.push_back(i);
        visited[i]=true;
    }
    cout<<vec.size()-1<<endl;
    if(vec.size()!=1)
    cout<<(vec[0]^vec[1]);
    for(int i=2;i<vec.size();i++){
        cout<<" "<<(vec[i]^vec[i-1]);
    }
    cout<<endl;
}
