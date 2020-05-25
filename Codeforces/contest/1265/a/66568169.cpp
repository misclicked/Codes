#include<bits/stdc++.h>
using namespace std;
string s;
bool gs=false;
bool dfs(int now){
	if(now==s.size())return gs=true;
	if(s[now]!='?')return dfs(now+1);
	bool flag=true;
	for(char c='a';c<='c';c++){
		bool pre,nxt;
		pre=now==0||s[now-1]!=c;
		nxt=now==s.size()-1||s[now+1]!=c;
		if(pre&&nxt){
			flag=false;
			s[now]=c;
			return dfs(now+1);
		}
		if(gs)return true;
	}
	if(flag)return false;
}
bool check(string str){
	for(int i=1;i<str.size();i++){
		if(str[i]==str[i-1])return false;
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>s;
		gs=false;
		if(dfs(0)&&check(s))cout<<s<<endl;
		else cout<<-1<<endl;
	}
} 