# Palindrome Reorder

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA

```cpp code
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> m;
    for (char c : s)
        m[c]++;
    int odd_count = 0;
    char odd_char;
    for (auto p : m)
    {
        if (p.second % 2 == 1)
        {
            odd_count++;
            odd_char = p.first;
        }
    }
    if (odd_count > 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string half = "";
    for (auto p : m)
    {
        half += string(p.second / 2, p.first);
    }
    string result = half;
    if (odd_count == 1)
        result += odd_char;
    reverse(half.begin(), half.end());
    result += half;
    cout << result << endl;
}
``` 