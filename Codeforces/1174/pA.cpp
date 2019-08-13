//
// Created by misclicked on 2019/6/4.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> vec;

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
    vec.resize(2*n);
    for(auto &it:vec)
        cin>>it;
    sort(vec.begin(),vec.end());
    if(*vec.begin()==*vec.rbegin()){
        cout<<-1<<endl;
    }else{
        cout<<vec[0];
        for(int i=1;i<2*n;i++){
            cout<<" "<<vec[i];
        }
        cout<<endl;
    }
}
