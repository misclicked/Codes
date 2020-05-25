#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char table[15];
int now[6]={12,6,4,3,2,1};
int main(){
	int t;
	bool flag;
	vector<int> ans;
	cin>>t;
	while(t--){
		ans.clear();
		for(int i=1;i<=12;i++)
			cin>>table[i];
		for(int i=0;i<6;i++){
			for(int k=1;k<=now[i];k++){
				flag=true;
				for(int j=0;j<12/now[i];j++){
					if(table[k+j*now[i]]!='X'){
						flag=false;
						break;
					}
				}
				if(flag){
					ans.push_back(now[i]);
					break;
				}
			}
		}
		cout<<ans.size();
		for(int i=0;i<ans.size();i++){
			cout<<" "<<12/ans[i]<<"x"<<ans[i];
		}
		if(t)
			cout<<endl;
	}
}