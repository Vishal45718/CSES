# Number Spiral
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

Your task is to find out the number in row y and column x.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.
Output
For each test, print the number in row y and column x.
Constraints

1 \le t \le 10^5
1 \le y,x \le 10^9

Example
Input:
3
2 3
1 1
4 2

Output:
8
1
15

***answer*** : To solve the problem of finding the number in a number spiral at a given row `y` and column `x`, we can derive a formula based on the properties of the spiral.
The number spiral can be visualized as follows:

```
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
``` 
the idea is to determine which layer of the spiral the coordinates (y, x) fall into. The layer can be determined by taking the maximum of y and x, which we will call `n`.
1. If `n` is odd, the bottom-right corner of the layer will be at (n, n) and the value at that position will be `n^2`. The numbers will fill the layer in a counter-clockwise manner starting from the bottom-right corner.
2. If `n` is even, the top-left corner of the layer will be at (n, n) and the value at that position will be `n^2`. The numbers will fill the layer in a clockwise manner starting from the top-left corner.
To find the number at (y, x):
- Determine `n = max(y, x)`.
- If `n` is odd:
  - If `y == n`, the number is `n^2 - (x - 1)`.
  - If `x == n`, the number is `n^2 - (n - y)`.
- If `n` is even:
  - If `y == n`, the number is `n^2 - (n - x)`.
  - If `x == n`, the number is `n^2 - (y - 1)`.
  
```cpp code

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long y, x;
        cin >> y >> x;

        long long n = max(y, x);
        long long ans;

        if (n % 2 == 0) {
            if (x == n)
                ans = (n - 1) * (n - 1) + y;
            else
                ans = n * n - x + 1;
        } else {
            if (y == n)
                ans = (n - 1) * (n - 1) + x;
            else
                ans = n * n - y + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
