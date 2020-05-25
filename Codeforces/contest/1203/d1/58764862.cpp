//
// Created by misclicked on 2019/8/13.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int,vector<int> > mape;

string s,t;

bool check(int i,int base,int n,bool ok){
    //cout<<i<<" "<<base<<" "<<n<<" "<<ok<<endl;
    int idx=lower_bound(mape[t[i]].begin(),mape[t[i]].end(),n+base)-mape[t[i]].begin();
    int idx2=lower_bound(mape[t[i]].begin(),mape[t[i]].end(),base)-mape[t[i]].begin();
    if(idx<mape[t[i]].size()){
        if(i==t.size()-1){
            return true;
        }
        return check(i+1,mape[t[i]][idx]+1,n,true)||check(i+1,mape[t[i]][idx2]+1,n,ok||false);
    }else{
        if(idx2<mape[t[i]].size()){
            if(i==t.size()-1){
                //cout<<s.size()<<" "<<mape[t[i]][idx2]<<endl;
                return ((s.size()-mape[t[i]][idx2]-1)>=n)||ok;
            }
            return check(i+1,mape[t[i]][idx2]+1,n,ok||false);
        }else{
            return false;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        mape[s[i]].push_back(i);
    }
    for(int i=0;i<t.size();i++){
        sort(mape[t[i]].begin(),mape[t[i]].end());
    }
    int L,R,MID,ans;
    L=0,R=s.size();
    while(L<=R){
        MID=(L+R)>>1;
        if(check(0,0,MID,false)){
            L=MID+1;
            ans=MID;
            //cout<<"GOOD"<<endl;
        }else{
            R=MID-1;
        }
    }
    cout<<ans<<endl;
}