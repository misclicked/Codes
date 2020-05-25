#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<int> vec;
int main(){
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		vec.push_back(data);
	}
	int front,rear;
	int ans=vec[0]<=t?1:0;
	front=0,rear=1;
	int now=vec[0];
	while(rear<n){
		while(now>t){
			now-=vec[front];
			front++;
		}
		ans=max(rear-front,ans);
		while(now<=t&&rear<n){
			now+=vec[rear];
			rear++;
			if(now<=t)
				ans=max(rear-front,ans);
		}
	}
	cout<<ans<<endl;
}
