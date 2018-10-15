#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MOD 39916801
#define N 100005
ll input[N];
int main()
{
    srand(time(0));
    for (int i = 0; i < 100000; i++)
    {
        ll data = (rand() * rand());
        if (input[data % MOD % N])
            cout << "bug" << endl;
        input[data % MOD % N] = 1;
    }
    system("pause");
}
