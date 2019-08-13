//
// Created by misclicked on 2019/6/2.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T>
std::ostream & operator<<(std::ostream & os, std::vector<T> vec)
{
    if(vec.size()!=0)
    {
        std::copy(vec.begin(), vec.end()-1, std::ostream_iterator<T>(os, " "));
        os<<vec.back();
    }
    return os;
}

int out[300005];
vector<int> vec[300005];
int vis[300005];
vector<int> ans;

void dfs(int n){
    if(vis[n])return;
    vis[n]=1;
    for(auto it:vec[n])
        dfs(it);
    ans.push_back(n);
}

void scanint(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    memset(out,0,sizeof(out));
    memset(vis,0,sizeof(vis));
    int n,m;
    int a,b;
    scanint(n);
    scanint(m);
    for(int i=0;i<m;i++){
        scanint(a);
        scanint(b);
        vec[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    cout<<ans<<endl;
}