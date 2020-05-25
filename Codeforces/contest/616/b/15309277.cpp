#include<bits/stdc++.h>
using namespace std;
int main(){
    int table[105];
    for(int i=0;i<105;i++)
        table[i]=INT_MAX;
    int m,n;
    int data;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>data;
            table[i]=min(data,table[i]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,table[i]);
    cout<<ans<<endl;
}