//
// Created by misclicked on 2019/5/16.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int input[300];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int T,n,i;
    ll ans;
    bool ok,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&input[i]);
        ok=true;
        sort(input,input+n);
        ans=1ll*input[0]*input[n-1];
        for(i=0;i<ceil(n/2.0);i++)
            if(1ll*input[i]*input[n-i-1]!=ans){
                ok=false;
                break;
            }
        if(ok)
            for(i=2;i<=1000;i++)
                if(ans%i==0&&ans!=i)
                    if(!binary_search(input,input+n,i)||!binary_search(input,input+n,ans/i)){
                        ok=false;
                        break;
                    }
        if(ok)
            printf("%I64d\n",ans);
        else
            puts("-1");
    }
}
