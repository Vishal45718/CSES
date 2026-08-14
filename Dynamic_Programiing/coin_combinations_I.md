# coin combinations I

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

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
8


idea : dp[x] = number of ways to make sum x using the coins
dp[0] = 1 (base case, one way to make sum 0)
dp[i] = sum(dp[i - c_j]) for all j such that c_j <= i (for each coin value c_j, if it can contribute to the sum i)


``` cpp code

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;

    vector<int> coins(n);
    
    for(int& coin : coins)
    {
        cin >> coin;
    }

    vector<long long> dp(x+1, 0);

    dp[0] = 1;

    for(int sum = 1; sum <=x ; sum++)
    {
        for(int coin : coins)
        {
            if(sum - coin >= 0)
            {
                dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}