
#include <bits/stdc++.h>
using namespace std;


int findDuplicate(const vector<int>& v) {
    int one,two,bit_mask;
    one=two=bit_mask=0;
    for(int i=0;i<v.size();i++) {
        two = two | (one & v[i]);
        one ^= v[i];
        bit_mask = ~(one & two);
        one &= bit_mask;
        two &= bit_mask;
        cout << one << " " << two << endl;
    }
    return two;
}

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i <= N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    cout << findDuplicate(v) << "\n";
    return 0;
}
