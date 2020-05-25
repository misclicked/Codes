#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        if (abs(x - y) % d == 0)
        {
            cout << abs(x - y) / d << endl;
            continue;
        }
        if (((y - 1) % d) && (n - y) % d)
        {
            cout << -1 << endl;
            continue;
        }
        int a = (y - 1) / d + ceil(((x - 1) * 1.0) / d);
        int b = (n - y) / d + ceil(((n - x) * 1.0) / d);
        if(((y - 1) % d) && (n - y) % d==0){
        	cout<<b<<endl;
		} else if(((y - 1) % d)==0 && (n - y) % d){
			cout<<a<<endl;
		}else{
        	cout << min(a, b) << endl;
		}
    }
}