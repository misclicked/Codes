#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<int> input;
int dp[105];
int main(){
	int n;
	cin>>n;
	int data;
	int one=0;
	for(int i=0;i<n;i++){
		cin>>data;
		if(data){
			input.push_back(-1);
			one++;
		}
		else input.push_back(1); 
	}
	int ans=-1e9;
	int now=0;
	for(int i=0;i<n;i++){
		if(now>0)now+=input[i];
		else now=input[i];
		ans=max(now,ans);
	}
	cout<<one+ans<<endl;
}
