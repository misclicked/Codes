//
// Created by misclicked on 2019/6/5.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int idx[300005]={0};
int input[300005]={0};
vector<pii> ans;

void Swap(int a,int b){
    ans.push_back({a,b});
    idx[input[a]]=b;
    idx[input[b]]=a;
    swap(input[a],input[b]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n;
    scanf("%d",&n);
    int data;
    for(int i=1;i<=n;i++){
        scanf("%d",&data);
        idx[data]=i;
        input[i]=data;
    }
    int step=n/2;
    for(int i=1;i<=n;i++){
        if(idx[i]!=i){
            if(idx[i]-i>=step){
                Swap(idx[i],i);
            }else{
                if(i<=step){
                    if(idx[i]<=step){
                        Swap(idx[i],n);
                        Swap(n,i);
                    }else{
                        int tmp=idx[i];
                        Swap(idx[i],1);
                        Swap(n,1);
                        Swap(n,i);
                        Swap(tmp,1);
                    }
                }else{
                    if(idx[i]<=step){
                        Swap(idx[i],n);
                        Swap(n,1);
                        Swap(1,i);
                        Swap(n,1);
                    }else{
                        int tmp=idx[i];
                        Swap(idx[i],1);
                        Swap(1,i);
                        Swap(tmp,1);
                    }
                }
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d %d\n",it.first, it.second);
    }
}
