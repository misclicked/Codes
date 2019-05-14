//
// Created by misclicked on 2019/5/8.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    int n;
    cin>>n;
    string s;
    vector<char> a,b;
    while(n--){
        cin>>s;
        a.clear();
        b.clear();
        for(int i=0;i<s.size();i++){
            if(s[i]&1)a.push_back(s[i]);
            else b.push_back(s[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        string ans="";
        int l=0,r=0;
        while((l+r)<s.size()){
            if(l<a.size())
                ans.push_back(a[l++]);
            if(r<b.size())
                ans.push_back(b[r++]);
        }
        bool ok=true;
        for(int i=0;i<ans.size()-1;i++){
            if(abs(ans[i]-ans[i+1])==1){
                ok=false;
                break;
            }
        }
        if(ok)
            cout<<ans<<endl;
        else
            cout<<"No answer"<<endl;
    }
}
