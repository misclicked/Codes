#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> a,b;

int main() {
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        a.resize(n);
        b.resize(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int l=0,r=n-1;
        while(k&&a[l]<b[r]){
            swap(a[l],b[r]);
            l++,r--,k--;
        }
        ll sum=0;
        for(int i=0;i<n;i++)sum+=a[i];
        cout<<sum<<endl;
    }
}
