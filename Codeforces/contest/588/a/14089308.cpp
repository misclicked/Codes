#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool compare(int a,int b){
    return a<b;
}
int main(){
    priority_queue<int,vector<int>,greater<int> > p;
    int n,tmp1,tmp2,ans=0;
    cin>>n;
    while(n--){
        cin>>tmp1>>tmp2;
        p.push(tmp2);
        ans+=tmp1*p.top();
    }
    cout<<ans<<endl;
}