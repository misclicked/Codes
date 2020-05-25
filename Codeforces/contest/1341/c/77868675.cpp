#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int dp[100005],mp[100005];

int main() {
    int t,n,d;
    cin>>t;
    set<int> se;
    map<int,int> mape;
    while(t--){
        cin>>n;
        se.clear();
        mape.clear();
        for(int i=1;i<=n;i++){
            cin>>d;
            mp[d]=i;
            dp[i]=1;
            se.insert(i);
            mape[1]++;
        }
        se.insert(n+1);
        int mx=1;
        string ans="Yes";
        for(int i=1;i<=n;i++){
            if(dp[mp[i]]==mx){
                mape[dp[mp[i]]]--;
                if(mape[dp[mp[i]]]==0)mape.erase(dp[mp[i]]);
               // cout<<mp[i]<<" "<<dp[mp[i]]<<" "<<mx<<endl;
                se.erase(mp[i]);
                int nxt=*se.lower_bound(mp[i]);
                dp[nxt]++;
                //cout<<nxt<<endl;
                if(nxt<=n){
                    mape[dp[nxt]]++;
                }
                if(mape.size())
                    mx=(*mape.rbegin()).first;
                   // cout<<"MX" <<mx<<" "<<(*mape.rbegin()).first<<endl;
            }else{
                ans="No";
                break;
            }
        }
        cout<<ans<<endl;
    }
}
