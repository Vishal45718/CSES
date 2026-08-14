# coin combinations II

Coin Combinations II
        
Task
Submit
Results
Analysis
Statistics
Tests
Queue

    
    









addEventListener("DOMContentLoaded", function (e) {
    const mathElements = document.getElementsByClassName("math");
    const macros = {};
    for (let element of mathElements) {
        katex.render(element.textContent, element, {
            displayMode: element.classList.contains("math-display"),
            throwOnError: false,
            globalGroup: true,
            macros,
        });
    }
});


.katex .base:last-child {
    display: inline;
}


Time limit: 1.00 s
Memory limit: 512 MB

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 9
2 3 5

Output:
3

idea : Dynamic Programming
- Create a DP array where dp[i] represents the number of ways to make sum i
- Initialize dp[0] = 1 (one way to make sum 0: use no coins)
- For each coin, update the DP array from left to right
- Return dp[x] modulo 10^9+7

``` cpp code

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    const int MOD = 1e9 + 7;
    vector<long long> dp(x + 1, 0);
    dp[0] = 1; // One way to make sum 0

    for (int coin : coins) {
        for (int j = coin; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
    }

    cout << dp[x] << endl;
    return 0;
}
```