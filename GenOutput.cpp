#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, in;
    vector<int> data, lib;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        data.push_back(in);
    }
    lib = data;
    sort(lib.begin(), lib.end());
    lib.erase(unique(lib.begin(), lib.end()), lib.end());

    for (auto i:data)
        cout << lower_bound(lib.begin(), lib.end(), i) - lib.begin() << " ";
    cout << endl;
}