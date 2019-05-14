//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int A[26],B[26];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
        A[a[i]-'A']++;
    for(int i=0;i<b.size();i++)
        B[b[i]-'A']++;
    int ans=INT_MAX;
    for(int i=0;i<26;i++){
        if(B[i])
            ans=min(ans,A[i]/B[i]);
    }
    cout<<ans<<endl;
}
