#include<bits/stdc++.h>
using namespace std;
vector<char> vec;
int main(){
	string input;
	int cnt;
	char now;
	cin>>input;
	now=input[0];
	cnt=1;
	input=input+"AP";
	for(int i=1;i<input.size();i++){
		if(input[i]==now){
			cnt++;
		}else{
			if(cnt==1){
				for(int i=0;i<vec.size();i++){
					if(i%2==0){
						cout<<vec[i]<<vec[i];
					}else{
						cout<<vec[i];
					}
				}
				vec.clear();
				if(i!=input.size()-1)
					cout<<now;
			}else if(cnt>1){
				vec.push_back(now);
			}
			cnt=1;
		}
		now=input[i];
	}
	cout<<endl;
}