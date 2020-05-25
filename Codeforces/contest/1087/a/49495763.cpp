#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
deque<char> input,ans;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		input.push_back(s[i]);
	int st,ed,typ;
	if(s.size()&1)typ=0;
	else typ=1;
	st=0;ed=s.size()-1;
	for(int i=0;i<s.size();i++){
		if(typ==0){
			ans.push_front(input[st++]);
		}else{
			ans.push_front(input[ed--]);
		}
		typ^=1;
	}
	for(int i=0;i<s.size();i++)
		cout<<ans[i];
	cout<<endl;
}
