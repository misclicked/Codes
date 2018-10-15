#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int eve,evei;
	int yee,yeei;
	eve=yee=0;
	int data;
	for(int i=0;i<n;i++){
		cin>>data;
		if(data%2){
			yee++;
			yeei=i;
		}else{
			eve++;
			evei=i;
		}
		if(i>=2){
			if(yee==1){
				cout<<yeei+1<<endl;
				break;
			}else if(eve==1){
				cout<<evei+1<<endl;
				break;
			}
		}
	}
}