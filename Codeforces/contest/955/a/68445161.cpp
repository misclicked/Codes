#import<bits/stdc++.h>
using namespace std;main(){double h,m,H,D,C,N;cin>>h>>m>>H>>D>>C>>N;cout<<min(ceil(H/N)*C,ceil((max(1200-h*60-m,0.0)*D+H)/N)*C*.8);}