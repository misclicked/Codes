#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll table[6][6];
int main(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			cin>>table[i][j];
		}
	}
	ll now[5]={1,2,3,4,5};
	ll ans=0;
	ll here;
	do{
		here=0;
		here+=table[now[2]][now[3]]+table[now[3]][now[2]];
		here+=table[now[3]][now[4]]+table[now[4]][now[3]];
		here*=2;
		here+=table[now[0]][now[1]]+table[now[1]][now[0]];
		here+=table[now[1]][now[2]]+table[now[2]][now[1]];
		ans=max(ans,here);
	}while(next_permutation(now,now+5));
	cout<<ans<<endl;
}