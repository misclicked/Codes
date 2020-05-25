#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,ta,tb,tc;
string s;
int main(){
    cin>>s;
    a=b=c=0;
    for(auto &it:s){
        if(it=='a')ta=a+1,tc=max(b+1,c+1);
        if(it=='b')tb=max(a+1,b+1);
        a=ta,b=tb,c=tc;
    }
    cout<<max({a,b,c})<<endl;
}