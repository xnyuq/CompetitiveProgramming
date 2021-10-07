#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef QUYNX_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int n; cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        ++mp[a];
        --mp[a+b];
    }
    vector<int> ans(n);
    int cur = 0;
    for (auto it = mp.begin(); it != mp.end(); ) {
        pair<int,int> pr = *(it++);
        if (it == mp.end()) break;
        cur += pr.second;
        if (cur > 0)  ans[cur-1] += (*it).first - pr.first;
    }
    for (auto &i: ans) cout << i << " ";
    cout << "\n";
}

