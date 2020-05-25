#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vec;
int fixmod(int i,int n){
	while(i<=0)i+=n;
	return i%n;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,m,c;
	cin>>n>>m>>c;
	vec.resize(n);
	fill(vec.begin(),vec.end(),-1);
	int data;
	while(cin>>data){
		if(data*2<=c){
			int i;
			for(i=0;i<n;i++){
				if(data<vec[i]||vec[i]==-1)
					break;
			}
			if(i==n)
				i--;
			cout<<i+1<<endl;
			vec[i]=data;
		}else{
			int i;
			for(i=n-1;i>=0;i--){
				if(data>vec[i]||vec[i]==-1)
					break;
			}
			if(i==-1)
				i++;
			cout<<i+1<<endl;
			vec[i]=data;
		}
		bool ok=true;
		for(int i=0;i<n-1;i++){
			if(vec[i+1]<vec[i]||vec[i]==-1||vec[i+1]==-1){
				ok=false;
				break;
			}
		}
		if(ok){
			return 0;
		}
		fflush(stdout);
	}
}