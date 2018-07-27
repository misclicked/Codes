#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int cnt[256]={0};
int main(){
	string s;
	for(int i=0;i<4;i++){
		cin>>ws;getline(cin,s);
		for(int j=0;j<s.size();j++){
			cnt[s[j]]++;
		}
	}
	int Max=0;
	for(int i='A';i<='Z';i++){
		Max=max(cnt[i],Max);
	}
	int present[256];
	int now=0;
	for(int i='Z';i>='A';i--){
		if(cnt[i]>now){
			for(int j=now;j<=cnt[i];j++){
				present[j]=i;
			}
			now=cnt[i];
		}
	}
	for(int i=Max-1;i>=0;i--){
		for(int j='A';j<=present[i];j++){
			if(cnt[j]>i)cout<<'*';
			else cout<<' ';
			if(j!=present[i])cout<<' ';
		}
		cout<<endl;
	}
	cout<<'A';
	for(int i='B';i<='Z';i++){
		cout<<' '<<(char)i;
	}
}

