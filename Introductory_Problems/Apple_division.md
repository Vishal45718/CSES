# Apple Division

There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,\dots,p_n: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints

1 \le n \le 20
1 \le p_i \le 10^9

Example
Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).

***idea*** : To solve this problem, we can use a recursive approach to explore all possible divisions of the apples into two groups. We can keep track of the total weight of each group and calculate the difference between them. The goal is to minimize this difference.

```cpp code
#include <bits/stdc++.h>
using namespace std;
int n;
long long p[20];
long long ans = LLONG_MAX;
void dfs(int i, long long sum1, long long sum2) {
    if (i == n) {
        ans = min(ans, abs(sum1 - sum2));
        return;
    }
    dfs(i + 1, sum1 + p[i], sum2); // Add apple i to group 1
    dfs(i + 1, sum1, sum2 + p[i]); // Add apple i to group 2
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}
```