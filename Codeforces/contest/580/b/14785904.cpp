#include<bits/stdc++.h>
#define MAX(a,b) a>b?a:b
using namespace std;
typedef long long ll;
int main(){
    vector< pair<ll,ll> > input;
    ll n,d,tmp1,tmp2,ans=0;
    cin>>n>>d;
    for(ll i=0;i<n;i++){
        cin>>tmp1>>tmp2;
        input.push_back(make_pair(tmp1,tmp2)); 
    } 
    sort(input.begin(),input.end());
    for(ll i=0;i<n;i++){
        ll sum=0;
        ll now=input[i].first;
        ll orgi=i;
        sum+=input[i].second;
        while(((input[i+1].first-input[i].first)<d)&&(i+1)<n){
            while((input[i+1].first-now)>=d){
                ans=max(sum,ans);
                sum-=input[orgi].second;
                orgi++;
                now=input[orgi].first;
            }
            sum+=input[i+1].second;
            i++;
        }
        ans=MAX(sum,ans);
    }
    cout<<ans<<endl;    
}