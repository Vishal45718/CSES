# Gray Code

A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.
Input
The only input line has an integer n.
Output
Print 2^n lines that describe the Gray code. You can print any valid solution.
Constraints

1 \le n \le 16

Example
Input:
2

Output:
00
01
11
10

***idea*** : the way is to generate the Gray code for n bits is to use the formula:
G(i) = i ^ (i >> 1)

To generate the Gray code for a given length n, you can use the formula G(i) = i ^ (i >> 1), where i is the integer representation of the binary number. This formula effectively generates the Gray code by performing a bitwise XOR operation between the integer i and its right-shifted version.

```cpp code

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int total = 1 << n; // Calculate 2^n
    for (int i = 0; i < total; i++) {
        int gray = i ^ (i >> 1); // Generate Gray code using the formula
        for (int j = n - 1; j >= 0; j--) {
            cout << ((gray >> j) & 1); // Print each bit of the Gray code
        }
        cout << endl; // Move to the next line after printing one Gray code
    }
    return 0;
}
```