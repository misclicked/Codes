#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;
int main(){
	int n;
	int data;
	vector<int> vec;
	stack<int> sol;
	stack<int> here;
	bool flag;
	bool blank=false;
	map<int,bool> mape;
	while(cin>>n){
		if(!n)return 0;
		while(cin>>data){
			vec.clear();
			if(!data)
				break;
			vec.push_back(data);
			for(int i=1;i<n;i++){
				cin>>data;
				vec.push_back(data);
			}
			while(!here.empty())here.pop();
			while(!sol.empty())sol.pop();
			for(int i=n;i>0;i--)
				sol.push(i);
			flag=true;
			for(int i=0;i<n;i++){
				if(here.empty()){
					if(sol.empty()){
						flag=false;
						break;
					}
					here.push(sol.top());
					sol.pop();
				}
				while(here.top()!=vec[i]){
					
					if(sol.empty()){
						flag=false;
						break;
					}
					here.push(sol.top());
					sol.pop();
				}
				if(flag==false)
					break;
				here.pop();
			}
			if(flag)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		cout<<endl;
	}
}