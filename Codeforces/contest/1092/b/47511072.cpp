#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main(){
    int n;
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int ans=0;
    for(int i=0;i<vec.size();i+=2){
        ans+=vec[i]-vec[i+1];
    }
    cout<<ans<<endl;
}
