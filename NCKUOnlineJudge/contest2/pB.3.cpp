#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
priority_queue<pii> hp;

int n, m, i, d;

int main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < m - 1; i++) {
        scanf("%d", &d);
        hp.push({d, i});
    }
    for (i = m - 1; i < n; i++) {
        scanf("%d", &d);
        hp.push({d, i});
        while (hp.top().second < i - m + 1)
            hp.pop();
        printf("%d ", hp.top());
    }
}