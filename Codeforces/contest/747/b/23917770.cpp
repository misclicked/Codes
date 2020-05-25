#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mape[66566];
vector<char> vec;
int main(){
	ll n;
	string input;
	cin>>n>>input;
	vec.clear();
	if(n%4){
		cout<<"==="<<endl;
		return 0;
	}
	memset(mape,0,sizeof(mape));
	for(int i=0;i<n;i++){
		mape[input[i]]++;
	}
	if(mape['A']>(n/4)){
		cout<<"==="<<endl;
		return 0;
	}else{
		for(int i=0;i<(n/4)-mape['A'];i++){
			vec.push_back('A');
		}
	}
	if(mape['T']>(n/4)){
		cout<<"==="<<endl;
		return 0;
	}else{
		for(int i=0;i<(n/4)-mape['T'];i++){
			vec.push_back('T');
		}
	}
	if(mape['G']>(n/4)){
		cout<<"==="<<endl;
		return 0;
	}else{
		for(int i=0;i<(n/4)-mape['G'];i++){
			vec.push_back('G');
		}
	}
	if(mape['C']>(n/4)){
		cout<<"==="<<endl;
		return 0;
	}else{
		for(int i=0;i<(n/4)-mape['C'];i++){
			vec.push_back('C');
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(input[i]=='?'){
			input[i]=vec[cnt++];
		}
	}
	cout<<input<<endl;
}