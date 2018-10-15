#include<iostream>
#include<set>
typedef long long ll;
using namespace std;
#define maxn 700000
int euler[maxn+5];
bool np[maxn+5];
inline void init_euler(){
	np[1]=1;//一不是質數
	for(int i=1;i<=maxn;i++)euler[i]=i;
	for(int i=2;i<=maxn;i++){
		if(!np[i]){//是質數
			euler[i]--;
			for(int j=i<<1;j<=maxn;j+=i){
				np[j]=1;
				euler[j]=euler[j]/i*(i-1);
			}
		}
	}
}
int main(){
	init_euler();
	ll n;
	while(~scanf("%I64d",&n)){
		cout<<euler[euler[n]]<<endl;
	}
}

