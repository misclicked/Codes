//
// Created by misclicked on 2019/5/16.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int np[2005000]={0};
vector<int> primes;
void build(){
    np[0]=1;
    np[1]=1;
    for(int i=2;i<=2004000;i++){
        if(!np[i])primes.push_back(i);
        for(int j=0;primes[j]*i<=2004000;j++){
            np[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}

vector<ll> vec;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    build();
    int T;
    cin>>T;
    while(T--){
        int n;
        ll data;
        cin>>n;
        vec.clear();
        for(int i=0;i<n;i++){
            cin>>data;
            vec.push_back(data);
        }
        bool ok=true;
        sort(vec.begin(),vec.end());
        ll ans=vec[0]*vec.back();
        int l,r;
        l=0,r=n-1;
        while(l<=r){
            if(vec[l++]*vec[r--]!=ans){
                ok=false;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(ans%vec[i]!=0){
                ok=false;
                break;
            }
        }
        ll cnt=1;
        ll Ans=ans;
        ll bound=ceil(sqrtl(ans));
        for(int i=0;primes[i]<=bound;i++){
            int here=1;
            while(ans%primes[i]==0){
                here++;
                ans/=primes[i];
            }
            cnt*=here;
        }
        if(ans!=1)cnt*=2;
        if((cnt-2)!=n)ok=false;
        if(ok)
            cout<<Ans<<endl;
        else
            cout<<-1<<endl;
    }
}
