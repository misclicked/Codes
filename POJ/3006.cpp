#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1000005
int np[MAXN]={0};
vector<int> prime;
void build(){
	np[0]=1;
	np[1]=1;
	for(int i=2;i<MAXN;i++){
		if(!np[i])
			prime.push_back(i);
		for(int j=0;i*prime[j]<MAXN;j++){
			np[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
		
	}
}
int main(){
	build();
	int a,d,n;
	while(cin>>a>>d>>n){
		if(!(a||d||n))return 0;
		int cnt=0;
		while(true){
			if(!np[a])cnt++;
			if(cnt==n){
				break;
			}
			a+=d;
		}
		cout<<a<<endl;
	}
}

