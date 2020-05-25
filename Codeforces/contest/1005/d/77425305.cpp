#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,ans;
int main(){
    string s;
    cin>>s;
    a=b=ans=0;
    for(int i=0;i<s.size();i++){
        int now=s[i]^'0';
        if(now%3==0)ans++,a=b=0;
        if(now%3==1){
            if(b==1)ans++,a=b=0;
            else if(a==1)b=1;
            else a=1;
        }
        if(now%3==2){
            if(a==1)ans++,a=b=0;
            else if(b==1)a=1;
            else b=1;
        }
    }
    cout<<ans<<endl;
}