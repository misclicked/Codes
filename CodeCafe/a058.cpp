//
// Created by misclicked on 2019/5/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void print(int n){
    if(n/2)
        print(n/2);
    cout<<n%2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    string s;
    while(cin>>s){
        int yee=0;
        bool first=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='y'){
                if(yee){
                    if(!first)
                        cout<<" ";
                    print(yee);
                    first=false;
                }else{
                    if(!first)
                        cout<<" 0";
                    first=false;
                }
                yee=0;
            }else{
                yee++;
            }
        }
        if(yee){
            if(!first)
                cout<<" ";
            print(yee);
            first=false;
        }else{
            if(!first)
                cout<<" 0";
            first=false;
        }
        cout<<endl;
    }

}