//
// Created by misclicked on 2019/6/2.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int input[10005];
int ss[10005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,m,data;
    cin>>n>>m;
    memset(input,0,sizeof(input));
    memset(ss,0,sizeof(ss));
    for(int i=0;i<m;i++)cin>>input[i];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>data;
            if(data!=input[j])
                ss[j]=1;
        }
    }
    int ans=-1,cnt=0;
    for(int i=0;i<m;i++){
        if(ss[i]){
            ans=max(ans,cnt);
            cnt=0;
        }else{
            cnt++;
        }
    }
    cout<<max(ans,cnt)<<endl;
}
