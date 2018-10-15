#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<vector>
#include<set>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<time.h>
using namespace std;
typedef long long ll;
int n,k,ans;
void dfs(int now,int d){
	if(d>=ans)return;
	ans=min(ans,d+abs(now-n));
	if(now==0)return;
	if(now%2){
		dfs((now+1)/2,d+2);
		dfs((now-1)/2,d+2);
	}else{
		dfs(now/2,d+1);
	}
}
int main(){
	ans=1e10;
	cin>>n>>k;
	dfs(k,0);
	cout<<ans<<endl;
}
