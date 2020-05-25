#include<iostream>
using std::cin;
main(){int t,n,a,b,d;cin>>t;while(t--){cin>>n>>a>>b;while(a--)cin>>d;while(b--)cin>>d,a=d==n?0:a;puts(a?"YES":"NO");}}