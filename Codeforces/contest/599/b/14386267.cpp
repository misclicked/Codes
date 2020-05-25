#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int n,m,now;
    int f[111111];
    int dic[111111];
    int ans[111111];
    bool amb[111111];
    bool im=false;
    bool am=false;
    cin>>n>>m;
    memset(dic,0,sizeof(dic));
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
        if(!dic[f[i]])
            dic[f[i]]=i;
        else
            amb[f[i]]=true;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&now);
        if(amb[now])
            am=true;
        if(dic[now])
            ans[i]=dic[now];
        else
            im=true;
    }
    if(am&&!im){
        cout<<"Ambiguity"<<endl;
        return 0; 
    }
    if(im){
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout<<"Possible"<<endl;
    cout<<ans[0];
    for(int i=1;i<m;i++)
        cout<<" "<<ans[i];
    cout<<endl;
} 