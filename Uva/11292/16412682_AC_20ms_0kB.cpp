#include<bits/stdc++.h>
using namespace std;
vector<int> head,knight;
int main(){
	int n,m;
	while(cin>>n>>m){
		if(!(n||m))return 0;
		int data;
		head.clear();knight.clear();
		for(int i=0;i<n;i++){
			cin>>data;
			head.push_back(data);
		}
		for(int i=0;i<m;i++){
			cin>>data;
			knight.push_back(data);
		}
		sort(head.begin(),head.end());
		sort(knight.begin(),knight.end());
		int h,k;
		h=k=0;
		int ans=0;
		while(h<n&&k<m){
			while((head[h]>knight[k])&&(k<m))
				k++; 
			if(head[h]>knight[k]){
				break;
			}
			ans+=knight[k];
			h++,k++;
		}
		if(h==n){
			cout<<ans<<endl;
		}else{
			cout<<"Loowater is doomed!"<<endl;
		}
	}
}