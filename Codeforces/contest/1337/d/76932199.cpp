#include<bits/stdc++.h>
#include<string>
#include<map>
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define vii         vector<pair<ll,ll> >
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define rep1(i,a,b) for(ll i=a;i<= b;i++)
#define PI          3.14159
#define MAX         100000001
#define fast_io      ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
#define scan(var)    scanf("%lld",&var)
#define print(var)   printf("%lld\n", var);
#define BLOCK 317
#define double       long double
#define mod          10007
using namespace std;
ll getjustmin(vector<ll>& v1,ll num)
{
  ll start = 0;
  ll end = v1.size() - 1;
  ll ans = v1[0];
  while(start <= end)
  {
    ll mid = (start + end) >> 1;
    if(v1[mid] > num)
    {
      end = mid - 1;
    }
    else
    {
      ans = v1[mid];
      start = mid + 1;
    }
  }
  return ans;
}
ll getjustmax(vector<ll>& v1,ll num)
{
  ll start = 0;
  ll end = v1.size() - 1;
  ll ans = v1[v1.size() - 1];
  while(start <= end)
  {
    ll mid = (start + end) >> 1;
    if(v1[mid] < num)
    {
      start = mid + 1;
    }
    else
    {
      ans = v1[mid];
      end = mid - 1;
    }
  }
  return ans;
}
ll getans(ll num1,ll num2,ll num3)
{
  ll sum1 = (num1 - num2)*(num1 - num2);
  ll sum2 = (num1 - num3)*(num1 - num3);
  ll sum3 = (num3 - num2)*(num3 - num2);
  return sum1 + sum2 + sum3;
}
int main()
{
  fast_io
  ll t;
  cin >> t;
  while(t--)
  {
    ll nr,ng,nb;
    cin >> nr >> ng >> nb;
    vector<ll> v1,v2,v3;
    rep(i,0,nr)
    {
      ll num;
      cin >> num;
      v1.pb(num);
    }
    rep(i,0,ng)
    {
      ll num;
      cin >> num;
      v2.pb(num);
    }
    rep(i,0,nb)
    {
      ll num;
      cin >> num;
      v3.pb(num);
    }
    ll ans = LLONG_MAX;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    rep(i,0,v1.size())
    {
      ll num = v1[i];
      ll num1 = getjustmin(v2,num);
      ll num2 = getjustmax(v3,num);
      ll ans1 = getans(num,num1,num2);
      ll num3 = getjustmin(v3,num);
      ll num4 = getjustmax(v2,num);
      ll ans2 = getans(num,num3,num4);
      ans = min(ans,min(ans1,ans2));
    }
    rep(i,0,v2.size())
    {
      ll num = v2[i];
      ll num1 = getjustmin(v1,num);
      ll num2 = getjustmax(v3,num);
      ll ans1 = getans(num,num1,num2);
      ll num3 = getjustmin(v3,num);
      ll num4 = getjustmax(v1,num);
      ll ans2 = getans(num,num3,num4);
      ans = min(ans,min(ans1,ans2));
    }
    rep(i,0,v3.size())
    {
      ll num = v3[i];
      ll num1 = getjustmin(v1,num);
      ll num2 = getjustmax(v2,num);
      ll ans1 = getans(num,num1,num2);
      ll num3 = getjustmin(v2,num);
      ll num4 = getjustmax(v1,num);
      ll ans2 = getans(num,num3,num4);
      ans = min(ans,min(ans1,ans2));
    }
    cout << ans << endl;
  }
  return 0;
}