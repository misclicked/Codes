#include<bits/stdc++.h>
using namespace std;
int mape[1235];
int main(){
	ios_base::sync_with_stdio(false);
	string input;
	cin>>input;
	if(input.length()<26){
		cout<<-1<<endl;
		exit(0);
	}
	vector<char> vec;
	memset(mape,0,sizeof(mape));
	int now=0;
	int start=0,end=0;
	for(int i=0;i<input.length();i++){
		if(isalpha(input[i])){
			if(mape[input[i]]){
				for(int k=start;;k++){
					mape[input[k]]--;
					now--;
					if(input[k]==input[i]){
						start=k+1;
						break;
					}
				}
				now++;
				mape[input[i]]++;
			}else{
				mape[input[i]]++;
				now++;
			}
		}else
			now++;
		if(now==26){
			end=i;
			break;
		}
	}
	if(now!=26){
		cout<<-1<<endl;
		exit(0);
	}
	vec.clear();
	memset(mape,0,sizeof(mape));
	for(int i=start;i<=end;i++){
		mape[input[i]]++;
	}
	for(int i=((int)'A');i<=((char)'Z');i++){
		if(!mape[i])
			vec.push_back((char)i);
	}
	int here=0;
	for(int i=start;i<=end;i++){
		if(input[i]=='?'){
			input[i]=vec[here];
			here++;
		}
	}
	for(int i=0;i<input.length();i++){
		if(input[i]=='?')
			input[i]='A';
	}
	cout<<input<<endl;
	return 0;
}