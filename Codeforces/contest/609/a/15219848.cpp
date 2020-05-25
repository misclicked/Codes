#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> q;
    int n,m;
    int data;
    cin>>n>>m;
    while(n--){
        cin>>data;
        q.push(data);
    }
    int ans=0;
    while(m>0){
        m-=q.top();
        q.pop();
        ans++;
    }
    cout<<ans<<endl;
}