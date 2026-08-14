# Raab game I

Consider a two player game where each player has n cards numbered 1,2,\dots,n. On each turn both players place one of their cards on the table. The player who placed the higher card gets one point. If the cards are equal, neither player gets a point. The game continues until all cards have been played.
You are given the number of cards n and the players' scores at the end of the game, a and b. Your task is to give an example of how the game could have played out.
Input
The first line contains one integer t: the number of tests.
Then there are t lines, each with three integers n, a and b.
Output
For each test case print YES if there is a game with the given outcome and NO otherwise.
If the answer is YES, print an example of one possible game. Print two lines representing the order in which the players place their cards. You can give any valid example.
Constraints

1 \le t \le 1000
1 \le n \le 100
0 \le a,b \le n

Example
Input:
5
4 1 2
2 0 1
3 0 0
2 1 1
4 4 1

Output:
YES
1 4 3 2
2 1 3 4
NO
YES
1 2 3
1 2 3
YES
1 2
2 1
NO

***idea*** : To solve this problem, we need to determine if it's possible for two players to achieve specific scores after playing a game with n cards each. We can use a greedy approach to construct a valid sequence of moves that leads to the desired scores.

```cpp code

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n || abs(a - b) > n - a - b) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        vector<int> p(n), q(n);
        iota(p.begin(), p.end(), 1);
        iota(q.begin(), q.end(), 1);

        int d = n - a - b;

        int idx = 0;

        // Draws
        while (d--) {
            p[idx] = idx + 1;
            q[idx] = idx + 1;
            idx++;
        }

        // Player 1 wins
        for (int i = 0; i < a; i++) {
            p[idx] = idx + 2;
            q[idx] = idx + 1;
            idx++;
        }

        // Player 2 wins
        for (int i = 0; i < b; i++) {
            p[idx] = idx + 1;
            q[idx] = idx + 2;
            idx++;
        }

        if (a > 0) {
            int l = n - b - a;
            int r = n - b;
            rotate(p.begin() + l, p.begin() + l + 1, p.begin() + r);
        }

        if (b > 0) {
            int l = n - b;
            int r = n;
            rotate(q.begin() + l, q.begin() + l + 1, q.begin() + r);
        }

        for (int x : p) cout << x << " ";
        cout << "\n";

        for (int x : q) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
```