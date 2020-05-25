#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int ans[1000006];
int cnt[1000006];
vector<int> idx[1000006];
int main() {
    ll t,n,k;
    cin>>t;
			vector<int> tmp;
    while(t--){
    	string s;
    	ll tot=0;
    	cin>>n>>k;
    	cin>>s;
    	for(int i=0;i<n;i++){
    		idx[i].clear();cnt[i]=ans[i]=0;
		}
    	for(int i=0;i<n;i++){
    		if(s[i]=='1'){
    			ans[i%k]++,tot++;
    			idx[i%k].push_back(i);
			}
    		cnt[i%k]++; 
		}
		ll A=LLONG_MAX;
		for(int i=0;i<k;i++){
			if(ans[i]==0)continue;
			ll outsider=(tot-ans[i]);
			ll sz=1;
			tmp.clear();
			for(int j=1;j<idx[i].size();j++){
				if(idx[i][j]-idx[i][j-1]==k){
					sz++;
				}else{
					tmp.push_back(-sz);
					tmp.push_back((idx[i][j]-idx[i][j-1])/k-1);
					sz=1;
				}
			}
			tmp.push_back(-sz);
			ll Min=LLONG_MAX, Minh=0;
			for(auto it:tmp){
				Minh += it;
				if(Minh < Min)
					Min = Minh;
				if(Minh > 0)
					Minh = 0;
			}
			A=min(A,ans[i]+Min+outsider);
		}
		if(A==LLONG_MAX)cout<<0<<endl;
		else cout<<A<<endl;
    }
}
