#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    int ap,an,bp,bn;
    int n;
    cin>>n;
    ap=an=bp=bn=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>=0)ap++;
        else an++;
        if(b>=0)bp++;
        else bn++;
    }
    if(ap==1||an==1||ap==0||an==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
