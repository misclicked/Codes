#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();cout.tie();
	int n,m;
	cin>>n>>m;
	string input;
	cin>>input;
	int l,r;
	char c1,c2;
	while(m--){
		cin>>l>>r>>c1>>c2;
		l--,r--;
		for(int i=l;i<=r;i++){
			if(input[i]==c1)input[i]=c2;
		}
	}
	cout<<input<<endl;
}
