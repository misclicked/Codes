#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> ans;
vector<int> G[505];
vector<pii> vec;
int dis[505];
int findLen(){
	int maxi=0;
	queue<int> que;
	que.push(1);
	memset(dis,-1,sizeof(dis));
	dis[1]=0;
	while(que.size()){
		int v=que.front();
		que.pop();
		maxi=v;
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i];
			if(dis[u]==-1){
				dis[u]=dis[v]+1;
				que.push(u);
			}
		}
	}
	que.push(maxi);
	memset(dis,-1,sizeof(dis));
	int ret;
	dis[maxi]=0;
	while(que.size()){
		int v=que.front();
		que.pop();
		ret=dis[v];
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i];
			if(dis[u]==-1){
				dis[u]=dis[v]+1;
				que.push(u);
			}
		}
	}
	return ret;
}
int main(){
	int n;
	cin>>n;
	vector<pii> link;
	vector<int> nlink;
	for(int i=1;i<=n;i++){
		int data;
		cin>>data;
		if(data>1)
			link.push_back(pii(data,i));
		else
			nlink.push_back(i); 
	}
	int degree=0;
	for(int i=0;i<(int)link.size()-1;i++){
		ans.push_back(pii(link[i].second,link[i+1].second));
		link[i].first--;
		link[i+1].first--;
	}
	for(int i=0;i<link.size();i++)degree+=link[i].first;
	if(degree<nlink.size()){
		cout<<"NO"<<endl;
		return 0;
	}
	int Ans=link.size()-1;
	if(nlink.size()>=1){
		Ans++;
		ans.push_back(pii(link[0].second,nlink[0]));
		link[0].first--;
	}
	if(nlink.size()>=2){
		Ans++;
		ans.push_back(pii(link[link.size()-1].second,nlink[1]));
		link[link.size()-1].first--;
	}
	for(int i=2;i<nlink.size();i++){
		for(int j=0;j<link.size();j++){
			if(link[j].first){
				link[j].first--;
				ans.push_back(pii(link[j].second,nlink[i]));
				break;
			}
		}
	} 
	cout<<"YES "<<Ans<<endl;
	cout<<ans.size()<<endl;
	for(auto it:ans){
		cout<<it.first<<" "<<it.second<<endl;
	}
}
