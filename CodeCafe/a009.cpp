//
// Created by misclicked on 2019/5/7.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int> > ans;
int table[30];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int now=0;
    memset(table,0,sizeof(table));
    for(int i=0;i<n;i++){
        int here=s[i]-'A';
        table[here]++;
    }
    int ansn=table[0];
    for(int i=1;i<m;i++)
        ansn=min(ansn,table[i]);
    for(int i=0;i<ansn;i++){
        vector<int> vec;
        vec.resize(m);
        ans.push_back(vec);
    }
    memset(table,0,sizeof(table));
    for(int i=0;i<n;i++){
        int here=s[i]-'A';
        table[here]++;
        if(table[here]<=ansn){
            ans[table[here]-1][here]=i+1;
        }
    }
    cout<<ansn<<endl;
    for(int i=0;i<ansn;i++){
        cout<<ans[i][0];
        for(int j=1;j<m;j++)
            cout<<" "<<ans[i][j];
        cout<<endl;
    }
}
