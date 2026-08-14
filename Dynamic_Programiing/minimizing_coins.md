# Minimizing COins

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 11
1 5 7

Output:
3

idea : 

dp[0] = 0 //sum 0 can be made with 0 coins
dp[i] = min(dp[i - c_j] + 1) for all j such that c_j <= i

- Space: O(x)
- Time Complexity
O(n × x)
n = number of coins
x = target sum
For every sum 1...x, we try all n coins.


``` cpp code

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for (int &c : coins) {
        cin >> c;
    }

    const int INF = 1e9;

    vector<int> dp(x + 1, INF);

    dp[0] = 0;

    for (int sum = 1; sum <= x; sum++) {
        for (int coin : coins) {
            if (coin <= sum && dp[sum - coin] != INF) {
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
            }
        }
    }

    if (dp[x] == INF)
        cout << -1 << '\n';
    else
        cout << dp[x] << '\n';

    return 0;
}

```