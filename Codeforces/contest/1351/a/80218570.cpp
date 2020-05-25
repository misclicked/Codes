#include <bits/stdc++.h>
using namespace std;
bool judge(int a,int b,int ans){
    return (a+b)==ans;
}
int main(){
    int t,ans,a,b;
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dis(-11351,11334);
    cin>>t;
    while(t--){
        cin>>a>>b;
        do{
            ans=dis(rng);
        }while(!judge(a,b,ans));
        cout<<ans<<endl;
    }
}