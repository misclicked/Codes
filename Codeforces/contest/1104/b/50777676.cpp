#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	string s;
	cin>>s;
	stack<char> sta;
	int n=0;
	for(int i=0;i<s.size();i++){
		if(sta.empty())sta.push(s[i]);
		else{
			if(s[i]==sta.top()){
				sta.pop();
				n++;
			}else{
				sta.push(s[i]);
			}
		}
	}
	cout<<(n%2?"Yes":"No")<<endl;
}
