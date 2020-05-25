//
// Created by misclicked on 2019/4/10.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
unordered_set<int> se;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int T;
    string s;
    cin>>T;
    while(T--){
        cin>>s;
        int Min=1111,Max=0;
        se.clear();
        for(int i=0;i<s.size();i++){
            Min=min(Min,(int)s[i]);
            Max=max(Max,(int)s[i]);
            se.insert(s[i]);
        }
        if((Max-Min+1)==se.size()&&se.size()==s.size()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}