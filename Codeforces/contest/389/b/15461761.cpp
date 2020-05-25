#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char mape[105][105];
int n;
int sol;
bool is(int x,int y){
	return mape[x][y]=='#'&&mape[x+1][y+1]=='#'&&mape[x+1][y-1]=='#'&&mape[x+2][y]=='#'&&mape[x+1][y]=='#';
}
void dfs(int x,int y){
	if(sol==0){
		cout<<"YES"<<endl;
		exit(0);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(is(i,j)){
				mape[i][j]=mape[i][j+1]=mape[i][j-1]=mape[i+1][j]=mape[i-1][j]='.';
				sol-=5;
				dfs(i,j);
				mape[i][j]=mape[i][j+1]=mape[i][j-1]=mape[i+1][j]=mape[i-1][j]='#';
				sol+=5;
			}
		}
	}
}
int main(){
	cin>>n;
	sol=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mape[i][j];
			if(mape[i][j]=='#')
				sol++;	
		}
	}
	if(sol%5!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	else if(sol==0){
		cout<<"YES"<<endl;
		return 0;
	}
	else{
		for(int i=0;i<n-2;i++){
			for(int j=1;j<n-1;j++){
				if(is(i,j)){
					mape[i][j]=mape[i+1][j+1]=mape[i+1][j-1]=mape[i+2][j]=mape[i+1][j]='.';
					sol-=5;
				}
			}
		}
	}
	if(sol)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}
