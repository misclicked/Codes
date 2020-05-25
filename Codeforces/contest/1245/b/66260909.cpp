#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	while(n--){
		cin>>m;
		int a,b,c,aa,bb,cc;
		aa=bb=cc=0;
		cin>>a>>b>>c;
		string s;
		cin>>s;
		for(char c:s){
			switch(c){
				case 'R':{
					aa++;
					break;
				}
				case 'P':{
					bb++;
					break;
				}
				case 'S':{
					cc++;
					break;
				}
			}
		}
		int win=min(aa,b)+min(bb,c)+min(cc,a);
		if(win<ceil(m/2.0)){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
			vector<char> vec;
			for(int i=0;i<b-aa;i++){
				vec.push_back('P');
			}
			for(int i=0;i<c-bb;i++){
				vec.push_back('S');
			}
			for(int i=0;i<a-cc;i++){
				vec.push_back('R');
			}
			int idx=0;
			for(char C:s){
				switch(C){
					case 'R':{
						if(b)putchar('P'),b--;
						else putchar(vec[idx++]);
						break;
					}
					case 'P':{
						if(c)putchar('S'),c--;
						else putchar(vec[idx++]);
						break;
					}
					case 'S':{
						if(a)putchar('R'),a--;
						else putchar(vec[idx++]);
						break;
					}
				}
			}
			puts("");
		}
	}
}