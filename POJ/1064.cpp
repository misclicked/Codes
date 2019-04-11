//
// Created by misclicked on 2019/4/11.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<ll> input;
ll n,m;
double data;
bool check(ll now){
    ll total=0;
    for(int i=0;i<n;i++){
        total+=input[i]/now;
        if(total>=m){
            return true;
        }
    }
    return total>=m;
}
int main() {
    cin>>n>>m;
    ll mx=0;
    for(int i=0;i<n;i++){
        scanf("%lf",&data);
        input.push_back(data*100);
        mx=max(mx,(ll)(data*100));
    }
    ll l=1,r=mx,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(ans<1){
        cout<<"0.00"<<endl;
        return 0;
    }
    ll ap = ans/100;
    ll bp = ans%100;
    cout<<ap<<".";
    if(bp==0){
        cout<<"00"<<endl;
    }else if(bp<10){
        cout<<"0"<<bp<<endl;
    }else{
        cout<<bp<<endl;
    }
}
