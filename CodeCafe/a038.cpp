//
// Created by misclicked on 2019/5/15.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> wait[100005];
vector<int> vec;
vector<int> ans;
priority_queue<int,vector<int>,greater<int> > pq;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif

    int n,m,k,K;
    while(cin>>n>>m>>k){
        K=k;
        for(int i=1;i<=n;i++)
            wait[i].clear();
        vec.clear();
        vec.resize(m);
        for(auto &it:vec) {
            cin >> it;
        }
        sort(vec.begin(),vec.end());
        int a,b;
        while(k--){
            cin>>a>>b;
            int data;
            for(int i=0;i<b;i++){
                cin>>data;
                wait[a].push_back(data);
            }
        }
        int orgcnt=0;
        ans.clear();
        while(pq.size())pq.pop();
        for(int j=0;j<wait[0].size();j++){
            pq.push(wait[0][j]);
        }
        for(int i=0;orgcnt<m||pq.size();i++){
            if(pq.size()&&(orgcnt>=m||pq.top()<vec[orgcnt])){
                ans.push_back(pq.top());
                pq.pop();
            }else{
                ans.push_back(vec[orgcnt++]);
            }
            for(int j=0;j<wait[i+1].size();j++){
                pq.push(wait[i+1][j]);
            }
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }

}
