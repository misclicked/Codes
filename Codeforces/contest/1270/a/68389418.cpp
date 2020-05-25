#import<iostream>
using std::cin;int n,a,b,d;main(){for(cin>>n;cin>>n>>a>>b;puts(a?"YES":"NO")){for(;a--;cin>>d);for(;b--;cin>>d,a=d-n?a:0);}}