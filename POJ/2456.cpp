//
// Created by misclicked on 2019/4/23.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N,C;
vector<int> vec;
bool check(int n){
    int here=vec[0];
    int remain=C-1;
    for(int i=1;i<N;i++){
        if(vec[i]-here>=n){
            here=vec[i];
            remain--;
        }
    }
    return remain<=0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    cin>>N>>C;
    vec.resize(N);
    for(int i=0;i<N;i++){
        cin>>vec[i];
    }
    int L=0,R=1e9,mid,ans=0;
    sort(vec.begin(),vec.end());
    while(L<=R){
        mid=(L+R)>>1;
        if(check(mid)){
            ans=mid;
            L=mid+1;
        }else{
            R=mid-1;
        }
    }
    cout<<ans<<endl;
}