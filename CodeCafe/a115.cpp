//
// Created by misclicked on 2019/5/6.
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
    deque<int> vec;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    vector<vector<int> > ans;
    while(vec.size()){
        vector<int> now;
        if(vec.front()==vec.back()){
            int test = vec.front();
            if(ans.size()<vec.size()){
                cout<<-1<<endl;
                return 0;
            }
            for(int i=0;i<vec.size();i++){
                if(ans[i].front()==test||ans[i].back()==test){
                    cout<<-1<<endl;
                    return 0;
                }
                ans[i].push_back(test);
                sort(ans[i].begin(),ans[i].end());
            }
            break;
        }
        now.push_back(vec.front());
        now.push_back(vec.back());
        vec.pop_back();
        vec.pop_front();
        ans.push_back(now);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].size();
        for(int j=0;j<ans[i].size();j++){
            cout<<" "<<ans[i][j];
        }
        cout<<endl;
    }
}
