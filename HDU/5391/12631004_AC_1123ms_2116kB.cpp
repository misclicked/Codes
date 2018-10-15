#include<iostream>
#include<set>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;
#define maxn 100000
bool np[maxn+5];
vector<int> primes;
void init(){
	np[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!np[i])primes.push_back(i);
		for(int j=0;i*primes[j]<=maxn;j++){
			np[i*primes[j]]=1;
			if(i%primes[j]==0)break;
		}
	}
}
int main(){
	init();
	int n;
	cin>>n;
	while(cin>>n){
		int cnt=0;
		for(int i=0;primes[i]*primes[i]<=n;i++){
			if(n%primes[i]==0)
				cnt++;
			if(cnt==2)break;
		}
		if(cnt==1&&((int)sqrt(n))*((int)sqrt(n))==n)
			cout<<(int)sqrt(n)<<endl;
		else if(cnt!=0)
			cout<<0<<endl;
		else
			cout<<n-1<<endl; 
	}
}
