#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int ans[200005];
vector<pii> vec;
int i=1;
void dfs(int l,int r){
	if(l>r)return;
	vec.push_back({(r-l),(l+r)/2});
	dfs(l,(l+r)/2-1);
	dfs((l+r)/2+1,r);
}
int main() {
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vec.clear();
        dfs(1,n);
        stable_sort(vec.begin(),vec.end(),[](const pii&a, const pii&b){
        	return a.first>b.first;
		});
		i=1;
        for(auto it:vec){
        	ans[it.second]=i++;
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
    }
}
