//
// Created by misclicked on 2019/6/2.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int input[1005]={0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n,m,k,hb=1,now,ans=-1,kk;
    string s;
    char c;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='1')
                input[j]^=hb;
        }
        hb<<=1;
    }
    vector<bool> vec(n,0);
    for(int i=n-k;i<n;i++)vec[i]=1;
    do{
        kk=*vec.begin()._M_p;
        now=0;
        for(int i=0;i<m;i++)
            if((kk|input[i])==kk)
                now++;
        ans=max(now,ans);
    }while(next_permutation(vec.begin(),vec.end()));
    cout<<ans<<endl;
}
