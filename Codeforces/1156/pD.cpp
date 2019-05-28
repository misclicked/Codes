//
// Created by misclicked on 2019/5/16.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int input[300],T,n,i,ok;
ll ans;

int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&input[i]);
        ok=1;
        sort(input,input+n);
        ans=1ll*input[0]*input[n-1];
        for(i=0;i<ceil(n/2.0);i++)
            if(1ll*input[i]*input[n-i-1]!=ans){
                ok=0;
                break;
            }
        if(ok)
            for(i=2;i<=1000;i++)
                if(ans%i==0&&ans!=i)
                    if(!binary_search(input,input+n,i)||!binary_search(input,input+n,ans/i)){
                        ok=0;
                        break;
                    }
        if(ok)
            printf("%I64d\n",ans);
        else
            puts("-1");
    }
}
