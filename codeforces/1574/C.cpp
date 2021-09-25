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
    vector<int64_t> a(n);
    int64_t sum = 0;
    for (auto &i: a) {
        cin >> i;
        sum += i;
    }
    int m; cin >> m;
    vector<int64_t> x(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    sort(a.begin(), a.end());
    int64_t mx = *max_element(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        int64_t altAns = -1;
        int64_t ans = 0, def = sum, atk = 0;
        if (mx <= x[i]) {
            atk = mx;
            def -= atk;
        }
        else {
            auto it = lower_bound(a.begin(), a.end(), x[i]);
            atk = *it;
            def -= atk;
            if (*it != x[i] && it != a.begin()) {
                // consider alternative solution
                --it;
                altAns = x[i] - *it + max(int64_t(0), y[i] - (sum - *it));
            }

        }
        ans = max(int64_t(0), x[i] - atk) + max(int64_t(0), y[i] - def);
        if (altAns != -1) ans = min(ans, altAns);
        if (i == 11) dbg(x[i], y[i], ans);
        cout << ans << "\n";
    }
}
// 62 8940
