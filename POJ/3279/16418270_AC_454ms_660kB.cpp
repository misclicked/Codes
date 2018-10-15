#include<iostream>
#include<cstring>
using namespace std;
int input[16][16];
int solve[16][16];
int ans[16][16];
int now[16][16];
int dir[5][2]={{0,0},{0,1},{1,0},{-1,0},{0,-1}};
int n,m;
int flip(int a,int b){
	now[a][b]=1;
	for(int i=0;i<5;i++){
		int aa = a+dir[i][0];
		int bb = b+dir[i][1];
		if(aa>=0&&aa<n&&b>=0&&b<m){
			solve[aa][bb]^=1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>input[i][j];
		}
	}
	int minTotal=1e9;
	for(int k=0;k<(1<<m);k++){
		memcpy(solve,input,sizeof(input));
		memset(now,0,sizeof(now));
		int total=0;
		for(int i=0;i<m;i++){
			if((k>>i)&1){
				total++;
				flip(0,m-i-1);
			}
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<m;j++){
				if(solve[i-1][j]){
					total++;
					flip(i,j);
				}
			}
		}
		bool ok=true;
		for(int i=0;i<m;i++){
			if(solve[n-1][i]){
				ok=false;
				break;
			}
		}
		if(ok&&total<minTotal){
			minTotal=total;
			memcpy(ans,now,sizeof(now));
		}
	}
	if(minTotal!=1e9){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	//cout<<minTotal<<endl;
}