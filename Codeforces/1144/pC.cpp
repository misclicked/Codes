//
// Created by misclicked on 2019/4/10.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> input,ansa,ansb;
unordered_map<int,int> mape;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        input.push_back(data);
        mape[data]++;
        if(mape[data]==3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    sort(input.begin(),input.end());
    ansa.push_back(input[0]);
    for(int i=1;i<n;i++){
        if(input[i]==input[i-1]){
            ansb.push_back(input[i]);
        }else{
            ansa.push_back(input[i]);
        }
    }
    reverse(ansb.begin(),ansb.end());
    cout<<"YES"<<endl;
    cout<<ansa.size()<<endl;
    cout<<ansa[0];
    for(int i=1;i<ansa.size();i++){
        cout<<" "<<ansa[i];
    }
    cout<<endl;
    cout<<ansb.size()<<endl;
    if(ansb.size()){
        cout<<ansb[0];
        for(int i=1;i<ansb.size();i++){
            cout<<" "<<ansb[i];
        }
    }
    cout<<endl;
}