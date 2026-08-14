#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int64 k;
        cin >> k;

        int64 digits = 1;
        int64 start = 1;

        while (true) {
            i128 cnt = (i128)9 * start * digits;
            if (k > cnt) {
                k -= (int64)cnt;
                digits++;
                start *= 10;
            } else
                break;
        }

        int64 number = start + (k - 1) / digits;
        int64 idx = (k - 1) % digits;

        string s = to_string(number);
        cout << s[idx] << '\n';
    }

    return 0;
}