//
// Created by misclicked on 2020/4/2.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif
string vec[118] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
                   "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
                   "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te",
                   "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm",
                   "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
                   "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr",
                   "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#else
    ios_base::sync_with_stdio(false);
    cin.tie();
#endif
    string s;
    cin >> s;
    bool nxt = false;
    string t(s);
    for (int i = 0; i < s.size(); i++) {
        bool ok = false;
        for (int j = 0; j < 118; j++) {
            if (vec[j].size() == 1) {
                if (tolower(s[i]) == tolower(vec[j][0])) {
                    ok = true;
                    t[i] = 'z';
                }
            } else {
                if (tolower(s[i]) == tolower(vec[j][0]) &&
                    tolower(s[i + 1]) == tolower(vec[j][1])) {
                    ok = true;
                    t[i] = 'z';
                    t[i + 1] = 'z';
                }
            }
        }
    }
    string ans = "YES";
    for (auto it:t) {
        if (it != 'z')ans = "NO";
    }
    cout << ans << endl;
}