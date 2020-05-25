#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
        vector<int> vec;
    while(t--){
        long long int sum,n,m,ans;
        cin>>n>>m;
        vec.resize(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        sort(vec.begin(),vec.end(),greater<int>());
        ans=0;
        sum=0;
        for(int i=1;i<=n;i++){
            sum+=vec[i-1];
            if(sum>=m*i)ans=i;
        }
        cout<<ans<<endl;
    }
}