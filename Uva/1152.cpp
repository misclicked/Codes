//
// Created by misclicked on 2019/4/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int A[4005],B[4005],C[4005],D[4005];
unordered_map<int,int> S;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int T;
    cin>>T;
    bool flag=false;
    while(T--){
        if(flag)cout<<endl;
        flag=true;
        int n;
        cin>>n;
        S.clear();
        for(int i=0;i<n;i++){
            cin>>A[i]>>B[i]>>C[i]>>D[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                S[C[i]+D[j]]++;
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=S[(A[i]+B[j])*-1];
            }
        }
        cout<<ans<<endl;
    }
}