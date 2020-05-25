#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
        vector<long long int> a,b;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);b.resize(n);
        for(int i=0;i<n;i++)cin>>a[i]>>b[i];
        long long int sum=0,ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            sum+=max(0ll,a[(i+1)%n]-b[i]);
        }
        //cout<<sum<<endl;
        for(int i=0;i<n;i++){
            ans=min(sum+a[i]-max(a[i]-b[(i-1+n)%n],0ll),ans);
        }
        cout<<ans<<endl;
    }
}