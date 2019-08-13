//
// Created by misclicked on 2019/5/15.
//

#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")

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
    string string1;
    string string2="012";
    while(cin>>string1){
        sort(string2.begin(),string2.end());
        int ans=INT_MAX;
        int sz=string1.size();
        do{
            int now=0;
            for(int i=0;i<sz;i+=3){
                if(string1[i]!=string2[0])now++;
                if(i+1<sz&&string1[i+1]!=string2[1])now++;
                if(i+2<sz&&string1[i+2]!=string2[2])now++;
            }
            ans=min(ans,now);
        }while(next_permutation(string2.begin(),string2.end()));
        cout<<ans<<endl;
    }
}
