#include <bits/stdc++.h>
using namespace std;

int main() {
    int n{}, result{-1}, x{0}, y{0};
    cin >> n;
    vector<int> a{}, b{};
    for (int i = 0; i < n; ++i) {
        int tmp{};
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        int tmp{};
        cin >> tmp;
        if (tmp && !a[i]) ++y;
        else if (!tmp && a[i]) ++x;
        b.push_back(tmp);
    }
    if (x > y) result = 1;
    if (y >= x && x != 0) result = ceil((float)(y+1)/x);
    cout << result << "\n";
}
