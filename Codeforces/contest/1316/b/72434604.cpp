#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	//freopen("output.txt","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string ans=s;
		int idx=1;
		string now;
		for(int i=1;i<=n;i++){
			now=s.substr(0,i-1);
			if((i+n)%2==0)
				reverse(now.begin(),now.end());
			now =  s.substr(i-1)+now;
			//cout<<i<<" "<<now<<endl;
			if(now<ans){
				ans=now;
				idx=i;
			}
		}
		cout<<ans<<endl;
		cout<<idx<<endl;
	}
} 