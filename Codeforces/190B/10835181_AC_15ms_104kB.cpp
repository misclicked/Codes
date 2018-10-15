#include<bits/stdc++.h>
using namespace std;
double distanse(double ax, double ay, double bx, double by){
	return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
int main(){
	double ax, ay, ar;
	double bx, by, br;
	cin>>ax>>ay>>ar;
	cin>>bx>>by>>br;
	double db = distanse(ax,ay,bx,by);
	if((ar+br)==db)
		cout<<"0"<<endl;
	else if((ar-db)==br)
		cout<<"0"<<endl;
	else if((br-db)==ar)
		cout<<"0"<<endl;
	else if((ar-db)>br)
		printf("%0.15lf\f",(ar-db-br)/2);
	else if((br-db)>ar)
		printf("%0.15lf\f",(br-db-ar)/2);
	else if((ar+br)>db)
		cout<<"0"<<endl;
	else
		printf("%0.15lf\f",(db-(ar+br))/2);
}