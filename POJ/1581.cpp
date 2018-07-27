#include<iostream>
#include<cstring>
#define INF 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	int n;
	cin>>n;
	string winner;
	int wintime=INF;
	int solved=-INF;
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		int a,b;
		int now=0;
		int nowsol=0;
		for(int j=0;j<4;j++){
			cin>>a>>b;
			if(b){
				now+=(a-1)*20+b;
				nowsol++;
			} 
		}
		if((nowsol>solved)||(nowsol==solved&&now<wintime)){
			solved=nowsol;
			wintime=now;
			winner=name;
		}
	}
	cout<<winner<<" "<<solved<<" "<<wintime<<endl;
}

