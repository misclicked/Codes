#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans=0,tmp1,tmp2;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int i=0;i<2*b;i+=2){
            cin>>tmp1>>tmp2;
            if(tmp1==1||tmp2==1)
                ans+=1;
        }
    }
    cout<<ans<<endl;
} 