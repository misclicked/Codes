#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,C,D;
int main(){
    cin>>A>>B>>C>>D;
    ll a,b,c,d;
    a=A,b=B,c=D,d=D;
    ll ans=0,now=1;
    ll MID=(A+B+B+C)/2;
    for(ll i=A+B;i<=B+C;i++){
        ans+=max((min(D,i-1)-C+1),0ll)*min({now,B-A+1,C-B+1});
        //cout<<max((min(D,i-1)-C+1),0ll)<<" "<<min({now,B-A+1,C-B+1})<<endl;
        if(i<MID)
            now++;
        else if(i>MID)
            now--;
        else if((A+B+B+C)%2==0&&i==MID)
            now--;
    }
    cout<<ans<<endl;
}