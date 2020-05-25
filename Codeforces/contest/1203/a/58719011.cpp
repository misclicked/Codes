//
// Created by misclicked on 2019/8/13.
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
    int T;
    cin>>T;
    int n;
    vector<int> s;
    string ans;
    while(T--){
        cin>>n;
        s.clear();
        int data;
        for(int i=0;i<n;i++){
            cin>>data;
            s.push_back(data-1);
        }
        bool oka,okb;
        ans="NO";
        for(int i=0;i<n;i++){
            oka=okb=true;
            for(int j=0;j<n;j++){
                //cout<<s[(i+j)%n]<<" "<<s[(i+j+1)%n]<<endl;
                if(s[(i+j)%n]!=(s[(i+j+1)%n]+1)%n)
                    oka=false;
                if(s[(i+j)%n]!=(s[(i+j+1)%n]-1+n)%n)
                    okb=false;
            }
            if(oka||okb){
                ans="YES";
                break;
            }
        }
        cout<<ans<<endl;
    }
}