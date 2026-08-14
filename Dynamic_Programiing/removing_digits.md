# Removing Digits

You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints

1 \le n \le 10^6

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.

idea : dp[i] = min(dp[i - d] + 1) for all digits d in i

``` cpp code

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x > 0)
        {
            int d = x % 10;
            if (d > 0)
                dp[i] = min(dp[i], dp[i - d] + 1);
            x /= 10;
        }
    }
    cout << dp[n] << endl;
}