#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
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

vector<int> reflexted{0,1,5,-1,-1,2,-1,-1,8,-1};

int H, M;
bool valid(int h, int m) {
    int ref_h = 0, ref_m = 0;
    bool rem = h < 10;
    while (h) {
        int digit = reflexted[h%10];
        if (digit == -1) return false;
        else ref_h = ref_h * 10 + digit;
        h /= 10;
    }
    if (rem) ref_h *= 10;
    rem = m < 10;
    while (m) {
        int digit = reflexted[m%10];
        if (digit == -1) return false;
        else ref_m = ref_m * 10 + digit;
        m /= 10;
    }
    if (rem) ref_m *= 10;
    return ref_h < M && ref_m < H;
}
int main() {
    //ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int h, m;
        scanf("%d %d\n%d:%d", &H, &M, &h, &m);
        while (true) {
            if (valid(h, m)) {
                if (h < 10) printf("0%d:", h);
                else printf("%d:", h);
                if (m < 10) printf("0%d", m);
                else printf("%d", m);
                break;
            }
            bool remainder = (m+1)/M;
            m = (m+1)%M;
            h = (h+remainder)%H;
        }
        cout << "\n";
    }
}

