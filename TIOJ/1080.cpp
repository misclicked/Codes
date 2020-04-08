//
// Created by misclicked on 2020/4/8.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int vec[100005];
long long ans = 0;

void merge(int start, int end)
{
    if (start >= end) return;
    int mid = start + ((end - start) >> 1);
    merge(start, mid);
    merge(mid + 1, end);
    for (int i = start; i <= mid; i++)
    {
        ans += distance(vec + mid + 1, lower_bound(vec + mid + 1, vec + end + 1, vec[i], less<int>()));
    }
    inplace_merge(vec + start, vec + mid + 1, vec + end + 1, less<int>());
}

int main()
{
    int n;
    int cnt = 1;
    while (scanf("%d", &n))
    {
        if (!n)break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vec[i]);
        }
        ans = 0;
        merge(0, n - 1);
        printf("Case #%d: %lld\n", cnt++, ans);
    }
}