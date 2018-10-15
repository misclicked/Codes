#include<bits/stdc++.h>
using namespace std;
int main(){
	string input;
	cin>>input;
	map<char,bool> mape;
	for(int i='a';i<='z';i++){
		mape[i]=false;
	}
	mape['a']=mape['e']=mape['i']=mape['o']=mape['u']=mape['y']=true;
	for(int i=0;i<input.length();i++){
		input[i]=tolower(input[i]);
		if(!mape[input[i]]){
			cout<<"."<<input[i];
		}
	}
	cout<<endl;
}