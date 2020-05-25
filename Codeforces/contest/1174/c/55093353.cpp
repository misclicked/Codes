//
// Created by misclicked on 2019/6/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int ans[100005];
int n;
void solve(){
    memset(ans,-1,sizeof(ans));
    int now=1;
    for(int i=2;i<=n;i++) {
        if(ans[i]==-1){
            ans[i]=now;
            for(int j=i*2;j<=n;j+=i){
                if(ans[j]==-1)
                    ans[j]=now;
            }
            now++;
        }
    }
    cout<<ans[2];
    for(int i=3;i<=n;i++){
        cout<<" "<<ans[i];
    }
    cout<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cin>>n;
    solve();
}
