#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W, H, x1, y1, x2, y2;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        int w, h;
        cin >> w >> h;
        if (w + x2 - x1 > W && h + y2 - y1 > H) {
            cout << "-1\n";
            continue;
        }
        int ans = 1e9;
        if (-x1 + x2 + w <= W) {
            if (x1 < w) {
                ans = w-x1;
            }
            else ans = 0;
            if (W-x2 < w){
                ans = min(ans, x2 - W + w);
            }
            else ans = 0;
        }
        if (y2 - y1 + h <= H) {
            if (y1 < h) {
                ans = min(ans, h-y1);
            }
            else ans = 0;
            if (H-y2 < h) ans = min(ans, y2 - H + h);
            else ans = 0;
        } 
        cout << ans << ".000000\n";
    }
}
