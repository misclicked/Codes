#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std;
int mape[111111111];
int main(){
	int n,data;
	int cnt=1;
	while(cin>>n){
		queue<int> now;
		queue<int> sol[1111];
		memset(mape,0,sizeof(mape));
		bool is[1111];
		memset(is,0,sizeof(is));
		if(!n)
			return 0;
		cout<<"Scenario #"<<cnt++<<endl;
		for(int i=1;i<=n;i++){
			int m;
			cin>>m;
			for(int j=0;j<m;j++){
				cin>>data;
				mape[data]=i;
			}
		}
		string input;
		bool flag=false;
		while(cin>>input){
			switch(input[0]){
				case 'E':{
					cin>>data;
					if(!is[mape[data]]){
						now.push(mape[data]);
						is[mape[data]]=true;
					}
					sol[mape[data]].push(data);
					break;
				}
				case 'D':{
					cout<<sol[now.front()].front()<<endl;
					sol[now.front()].pop();
					if(sol[now.front()].empty()){
						is[now.front()]=false;
						now.pop();
					}
					break;
				}
				case 'S':{
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
		cout<<endl;
	}
}