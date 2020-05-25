#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n,m;
	cin>>n>>m;
	vector<int> games;
	vector<int> bills;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		games.push_back(data);
	}
	for(int i=0;i<m;i++){
		int data;
		cin>>data;
		bills.push_back(data);
	}
	int ans=0;
	int j=0;
	for(int i=0;i<n;i++){
		if(bills[j]>=games[i]){
			ans++;
			j++;
			if(j==m)break;
		}
	}
	cout<<ans<<endl;
}
