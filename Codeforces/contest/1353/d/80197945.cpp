#import <bits/stdc++.h>
using namespace std;
#define f for(i=1;i<=n;i++)
int a[200005],i,n;
pair<int,int> b[200005];
void d(int l,int r){
	if(l>r)return;
    int m=(l+r)/2;
	b[m]={l-r,m};
	d(l,m-1);d(m+1,r);
}
int main() {
    cin>>n;
    while(cin>>n){
        d(1,n);
        sort(b+1,b+1+n);
        f a[b[i].second]=i;
		f cout<<a[i]<<" ";
        puts("");
    }
}