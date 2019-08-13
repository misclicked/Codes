//
// Created by misclicked on 2019/4/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> vec,vec2;
vector<int> ans;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #else
    ios_base::sync_with_stdio(false);
    cin.tie();
    #endif
    cin>>ws;
    string input;
    while(getline(cin,input)){
        stringstream ss(input);
        int data;
        vec.clear();
        vec2.clear();
        ans.clear();
        cout<<input<<endl;
        while(ss>>data){
            vec.push_back(data);
            vec2.push_back(data);
        }
        sort(vec2.begin(),vec2.end());
        reverse(vec2.begin(),vec2.end());
        int now=0;
        int Swap=0;
        while(!is_sorted(vec.begin(),vec.end())){
            for(int i=0;i<vec.size();i++){
                if(vec[i]==vec2[now]){
                    Swap=i;
                    break;
                }
            }
            if(Swap!=0&&vec[vec.size()-now-1]!=vec2[now]){
                reverse(vec.begin(),vec.begin()+Swap+1);
                ans.push_back(vec.size()-Swap);
            }
            if(vec[vec.size()-now-1]!=vec2[now]){
                reverse(vec.begin(),vec.end()-now);
                ans.push_back(now+1);
            }
            now++;
        }
        ans.push_back(0);
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
        cin>>ws;
    }
}