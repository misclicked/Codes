#include<iostream>
using std::cin;main(){int n,a,b,d;cin>>n;while(cin>>n>>a>>b){for(;a--;)cin>>d;while(b--)cin>>d,a=d==n?0:a;puts(a?"YES":"NO");}}