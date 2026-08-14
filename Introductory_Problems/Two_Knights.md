# Two Knights
Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.
Input
The only input line contains an integer n.
Output
Print n integers: the results.
Constraints

1 \le n \le 10000

Example
Input:
8

Output:
0
6
28
96
252
550
1056
1848

***answer*** : To solve this problem, we can use a dynamic programming approach. The number of ways to place two knights on a k x k chessboard can be calculated using the formula:
Total ways to place two knights = (k * k) * (k * k - 1) / 2
Number of attacking positions = 4 * (k - 1) * (k - 2)
Number of non-attacking positions = Total ways to place two knights - Number of attacking positions
```cpp code
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[1] = 0; // For 1x1 board, no way to place two knights
    for (int k = 2; k <= n; k++) {
        long long total = (long long)k * k * (k * k - 1) / 2;
        long long attacking = 4 * (k - 1) * (k - 2);
        dp[k] = total - attacking;
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << '\n';
    }
    return 0;
}
```
