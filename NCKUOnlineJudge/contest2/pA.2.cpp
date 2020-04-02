#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

char input[2005];

size_t n, m, val;

cc_hash_table<size_t, int> se;

int top = 0;
size_t sta[20005];

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        if (m == 1) {
            fgets(input, 2001, stdin);
            val = hash<string>()(input);
            se[val]++;
            sta[top++] = val;
        } else if (m == 2) {
            if (top)
                se.erase(sta[--top]);
        } else {
            fgets(input, 2001, stdin);
            val = hash<string>()(input);
            putchar(se[val] ? 'Y' : 'N');
        }
    }
}