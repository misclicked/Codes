#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	string s;
	cin>>s;
	/*2|0
	0|2
	100|21|0
	001|12|0*/
	string ans="";
	int ones=0;
	for(auto it:s){
		if(it=='1')ones++;
		else ans.push_back(it);
	}
	bool flag=false;
	for(auto it:ans){
		if(it=='2'&&!flag){
			for(int i=0;i<ones;i++)cout<<1;
			flag=true;
		}
		cout<<it;
	}
	if(!flag)
		for(int i=0;i<ones;i++)cout<<1;
	cout<<endl;
	/*2102
	1202
	2012
	2021
	2012
	2102
	1202!!!*/
	/*2012
	1202
	2xxxxxxxxxx2xxxxxxxxxxxx2
	xxxxx2xxxxxxx2
	*/
	/*100210
	0020
	0020
	00222220000002222*/
}
