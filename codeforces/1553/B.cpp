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
    int t;
    cin >> t;
    while (t--) {
        string S, T; cin >> S >> T;
        string revS; revS.resize(S.length());
        int n = S.length();
        reverse_copy(S.begin(), S.end(), revS.begin());
        bool found = false;
        for (int pos = 0; pos < n; ++pos) {
            for (int turnRight = 0; pos + turnRight < n; ++turnRight) {
                int turnLeft = (int)T.length() - 1 - turnRight;
                if (pos + turnRight - turnLeft < 0) continue;
                string cur = S.substr(pos, turnRight + 1) + revS.substr(n-pos-turnRight, turnLeft);
                if (T == cur) found = true;
                    //pos+turnRight-1 -> n-pos-turnRight
            }
        }
        cout << (found ? "yes\n" : "no\n");
    }
}
