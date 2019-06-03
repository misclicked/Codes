//
// Created by misclicked on 2019/6/2.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

multiset<int> front,rear;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int a,b;
    int sz=0;
    cout<<fixed;
    while(cin>>a>>b){
        switch(a){
            case 1:{
                sz++;
                if(front.empty()){
                    front.insert(b);
                }else if(b>*front.rbegin()){
                    rear.insert(b);
                }else{
                    front.insert(b);
                }
                if(rear.size()>front.size()){
                    front.insert(*rear.begin());
                    rear.erase(rear.begin());
                }
                if((int)rear.size()<(int)front.size()-1){
                    rear.insert(*front.rbegin());
                    front.erase(--front.end());
                }
                if(sz&1)
                    cout<<setprecision(1)<<(double)*front.rbegin()<<endl;
                else
                    cout<<setprecision(1)<<(*front.rbegin()+*rear.begin())/2.0<<endl;
                break;
            }
            case 2:{
                if(front.count(b)){
                    front.erase(front.find(b));
                    cout<<"ok"<<endl;
                    sz--;
                }else if(rear.count(b)){
                    rear.erase(rear.find(b));
                    cout<<"ok"<<endl;
                    sz--;
                }else{
                    cout<<"skip"<<endl;
                }
                //cout<<rear.size()<<" "<<front.size()<<endl;
                if(rear.size()>front.size()){
                    front.insert(*rear.begin());
                    rear.erase(rear.begin());
                }
                if((int)rear.size()<(int)front.size()-1){
                    rear.insert(*front.rbegin());
                    front.erase(--front.end());
                }
                break;
            }
        }
    }
}
