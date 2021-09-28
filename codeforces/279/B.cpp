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
    int n, t; cin >> n >> t;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    int ans = 0, cur = 0;
    int left = 0, right = 0;
    while (left < n && right < n) {
        while (right < n) {
            cur += arr[right++];
            if (cur > t) {
                cur -= arr[--right];
                break;
            }
        }
        ans = max(ans, right - left);
        cur -= arr[left++]; // loop step
    }
    cout << ans;
}
