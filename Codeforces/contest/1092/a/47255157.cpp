#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		int minfreq=a/b;
		int cnt=0;
		for(int i=1;i<b;i++){
			for(int j=0;j<minfreq;j++){
				cout<<(char)('a'+i-1);
				cnt++;
			}
		}
		for(int i=cnt;i<a;i++){
			cout<<(char)('a'+b-1);
		}
		cout<<endl;
	}
}