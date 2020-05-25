#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int D,U,L;
		D=U=L=0;
		for(int i=0;i<s.size();i++){
			if(isdigit(s[i]))D++;
			if(islower(s[i]))L++;
			if(isupper(s[i]))U++;
		} 
		if(D&&U&&L){
		}else if(D&&U){
			if(D>U){
				for(int i=0;i<s.size();i++){
					if(isdigit(s[i])){
						s[i]='a';
						break;
					}
				}	
			}else{
				for(int i=0;i<s.size();i++){
					if(isupper(s[i])){
					s[i]='a';
						break;
					}
				}	
			}
		}else if(D&&L){
			if(D>L){
				for(int i=0;i<s.size();i++){
					if(isdigit(s[i])){
					s[i]='A';
						break;
					}
				}	
			}else{
				for(int i=0;i<s.size();i++){
					if(islower(s[i])){
					s[i]='A';
						break;
					}
				}	
			}
		}else if(U&&L){
			if(U>L){
				for(int i=0;i<s.size();i++){
					if(isupper(s[i])){
					s[i]='1';
						break;
					}
				}	
			}else{
				for(int i=0;i<s.size();i++){
					if(islower(s[i])){
					s[i]='1';
						break;
					}
				}	
			}
		}else{
			if(D){
				s[0]='a';s[1]='A';
			}else if(U){
				s[0]='1';s[1]='a';
			}else{
				s[0]='1';s[1]='A';
			}
		}
		cout<<s<<endl;
	}
}