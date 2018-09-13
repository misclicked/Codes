#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef struct factory
{
    float price;
    float power;
    float cp;
    bool available;
};
vector<factory> factorys;
int main()
{
    int N, C, S;
    cin >> N >> C >> S;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        factory f;
        cin >> f.price >> f.power;
        f.cp = f.price / f.power;
        f.available = true;
        factorys.push_back(f);
    }
    sort(factorys.begin(), factorys.end(), [](const factory &a, const factory &b) {
        return a.cp < b.cp;
    });
    int nowpower = S;
    int nowcoin = 0;
    int cnt = 0;
    while (true)
    {
        cnt++;
        nowcoin += nowpower;
        while (true)
        {
            bool canbuy = false;
            for (int i = 0; i < factorys.size(); i++)
            {
                if (factorys[i].available)
                {
                    if (nowcoin >= factorys[i].price)
                    {
                        if (nowcoin + nowpower * ceil(factorys[i].cp) < C)
                        {
                            canbuy = true;
                            factorys[i].available = false;
                            nowpower += factorys[i].power;
                            nowcoin -= factorys[i].price;
                            // cout << "buy " << factorys[i].price << endl;
                            break;
                        }
                    }
                }
            }
            if (!canbuy)
                break;
        }
        if (nowcoin >= C)
        {
            cout << cnt << endl;
            system("pause");
            return 0;
        }
    }
}