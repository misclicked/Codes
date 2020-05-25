#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mape;
unordered_map<int,bool> ans;
vector<int> vec;
int main(){
	int n;
	cin>>n;
	int data;
	for(int i=0;i<n;i++){
		cin>>data;
		vec.push_back(data);
		mape[data]++;
	}
	int A,B;
	A=B=0;
	for(auto it:mape){
		if(it.second==1)A++;
		else if(it.second!=2)B++;
	}
	//	cout<<A<<" "<<B<<endl;
	if(A==B){
		cout<<"YES"<<endl;
		for(auto it:mape){
			if(it.second==1){
				ans[it.first]=false;
			}else if(it.second!=2){
				ans[it.first]=true;
			}
		}
		for(int i=0;i<n;i++){
			if(!ans[vec[i]])cout<<'A';
			else {
				cout<<'B';
				ans[vec[i]]=false;
			}
		}
		cout<<endl;
		return 0;
	}else if(A>B){
		int BdontGO=0;
		int AdontGO=0;
		if(((A-B)%2)&&B==0){
			cout<<"NO"<<endl;
			return 0;
		}else if((A-B)%2){
			BdontGO=1;
			AdontGO=(A-B+1)/2;
		}else{
			AdontGO=(A-B)/2;
		}
		cout<<"YES"<<endl;
		for(auto it:mape){
			if(it.second==1){
				if(AdontGO){
					ans[it.first]=true;
					AdontGO--;
				}else
					ans[it.first]=false;
			}else if(it.second!=2){
				if(BdontGO){
					ans[it.first]=false;
					BdontGO--;
				}else
					ans[it.first]=true;
			}
		}
		for(int i=0;i<n;i++){
			if(mape[vec[i]]==1){
				if(ans[vec[i]]){
					cout<<'B';
				}else
					cout<<'A';
			}
			else if(mape[vec[i]]==2){
				cout<<'B';	
			}else{
				if(!ans[vec[i]]){
					cout<<'A';
					BdontGO--;
				}else{
					ans[vec[i]]=false;
					cout<<'B';
				}
			}
		}
	}else{
		int BdontGO=0;
		if(A==0){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				cout<<'A';
			}
			cout<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		BdontGO=B-A;
		for(auto it:mape){
			if(it.second==1){
				ans[it.first]=false;
			}else if(it.second!=2){
				if(BdontGO){
					ans[it.first]=false;
					BdontGO--;
				}else
					ans[it.first]=true;
			}
		}
		for(int i=0;i<n;i++){
			if(mape[vec[i]]==1){
				cout<<'A';
			}
			else if(mape[vec[i]]==2){
				cout<<'B';
			}else{
				if(!ans[vec[i]]){
					cout<<'A';
				}else{
					ans[vec[i]]=false;
					cout<<'B';
				}
				
			}
		}
	}
	cout<<endl;
}