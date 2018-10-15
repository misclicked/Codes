#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std;
typedef unsigned long long ull;
int main(){
	ull n;
	cin>>n;
	while(n--){
		string input;
		cin>>input;
		ull rt,rb;
		rt=1,rb=0;
		ull lt,lb;
		lt=0,lb=1;
		ull at,ab;
		at=ab=1;
		for(ull i=0;i<input.size();i++){
			switch(input[i]){
				case 'R':{
					lt=at;
					lb=ab;
					at+=rt;
					ab+=rb;
					break;
				}
				case 'L':{
					rt=at;
					rb=ab;
					at+=lt;
					ab+=lb;
					break;
				}
			}
		}
		cout<<at<<"/"<<ab<<endl;
	}
}