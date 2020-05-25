#include<bits/stdc++.h>
using namespace std;
int vec[1005]={0};
int main(){
	int n,m,c,i,cnt,data;
	cin>>n>>m>>c;
	cnt=0;
	while(cin>>data){
		if(data*2<=c){
			i=0;
			while(!((data<vec[i]||!vec[i])))i++;
			cout<<i+1<<endl;
			if(!vec[i])cnt++;
			vec[i]=data;
		}else{
			i=n-1;
			while(!((data>vec[i]||!vec[i])))i--;
			cout<<i+1<<endl;
			if(!vec[i])cnt++;
			vec[i]=data;
		}
		if(cnt==n)exit(0);
		fflush(stdout);
	}
}