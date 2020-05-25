#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> G;
int main(){
	/*5 6
	1 2 3 4 5
	1: 2 3 4 5
	2: 3 5
	3: 4 5
	4: 5
	5:*/
	int n,m;
	cin>>n>>m;
	if(m<n-1){
		cout<<"Impossible"<<endl;
		return 0;//FK
	}
	for(int i=2;i<=n;i++){
		G.push_back(pii(1,i));
	}
	if(G.size()>=m){
		cout<<"Possible"<<endl;
		for(int k=0;k<G.size();k++){
			cout<<G[k].first<<" "<<G[k].second<<endl;
		}
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(__gcd(i,j)==1){
				G.push_back(pii(i,j));
				if(G.size()>=m){
					cout<<"Possible"<<endl;
					for(int k=0;k<G.size();k++){
						cout<<G[k].first<<" "<<G[k].second<<endl;
					}
					return 0;
				}
			}
		}
	}
	cout<<"Impossible"<<endl;
}
