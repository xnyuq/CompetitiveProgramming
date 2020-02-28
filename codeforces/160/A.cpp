//https://codeforces.com/problemset/problem/160/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n{},sum{}, count{0}, mymoney{};
    vector<int> a{};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp{};
        cin >> tmp;
        a.push_back(tmp);
        sum += tmp;
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        mymoney += a[i];
        ++count;
        if (mymoney > sum - mymoney) 
            break;
    }
    cout << count << "\n";

}
