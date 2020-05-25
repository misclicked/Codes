#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n,t;
	cin>>n;
	cin>>t;
	int cnt;
	n--;
	int old,now;
	cnt = 0;
	cin>>old;
	cnt++;
	while(n--){
		cin>>now;
		if(now-old>t)
			cnt=1;
		else
			cnt++;
		old=now;
	}
	cout<<cnt<<endl;
}