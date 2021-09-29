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
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<pair<int,int>, greater<pair<int,int>>> s;
        for (int i = 1; i <= n; ++i) {
            int tmp; cin >> tmp;
            if (tmp > 0) s.insert({tmp, i});
        }
        vector<array<int,2>> ans;
        while (s.size() > 1) {
            auto it = s.begin();
            pair<int,int>  fi = *it, se = *(++it);
            s.erase(s.begin());
            s.erase(s.begin());
            ans.push_back({fi.second, se.second});
            --fi.first; --se.first;
            if (fi.first > 0) s.insert(fi);
            if (se.first > 0) s.insert(se);
        }
        cout << ans.size() << "\n";
        for (auto& v: ans) {
            cout << v[0] << " " << v[1] << "\n";
        }
    }
}

