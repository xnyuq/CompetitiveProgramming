#include <bits/stdc++.h>
using namespace std;

int compare(int a, int b) {
    int result{0};
    if (a > b) {
        if (a % 2 == b % 2) result = 1;
        else result = 2;
    }
    else if (a < b) {
        if (a % 2 == b % 2) result = 2;
        else result = 1;
    }
    return result;
}
int main() {
    int n{}, a{}, b{};
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << compare(a,b) << "\n";
    }
}
