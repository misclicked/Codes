#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;
int mape[100005];
int input[100005];
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;
order_set os;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int data;
            cin >> data;
            input[i] = data;
            mape[data] = i;
        }
        ll ans = 0;
        os.clear();
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            os.insert(mape[data]);
            ans += i - os.order_of_key(mape[data]);
            //cout << mape[data] << " " << os.order_of_key(mape[data]) << endl;
        }
        cout << ans << endl;
    }
    //system("pause");
}