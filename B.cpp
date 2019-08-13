//
// Created by misclicked on 2019/5/5.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
int a[3000006];
int lisl[3000006];
int lisr[3000006];
int l[10];
int r[10];

int solve(){
    for(int i=0;i<n;i++){
        l[i]=r[i]=lisl[i]=lisr[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            lisl[i]=max(lisl[i],l[j]+1);
        }
        l[a[i]]=lisl[i];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<a[i];j++){
            lisr[i]=max(lisr[i],r[j]+1);
        }
        r[a[i]]=lisr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,lisl[i]+lisr[i]-1);
    }
    return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputB.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    while(cin>>n){
        string s;
        cin>>s;
        for(int i=0;i<n;i++)a[i]=s[i]-'0';
        cout<<solve()<<endl;
    }
}