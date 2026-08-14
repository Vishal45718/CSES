# Creating Strings

Given a string, your task is to generate all different strings that can be created using its characters.
Input
The only input line has a string of length n. Each character is between a–z.
Output
First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.
Constraints

1 \le n \le 8

Example
Input:
aabac

Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa

***idea*** : To generate all different strings that can be created using the characters of a given string, we can use a recursive backtracking approach. We will keep track of the characters used and ensure that we do not generate duplicate strings by sorting the input string and skipping over duplicate characters during the recursion.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end()); // Sort the string to handle duplicates
    set<string> result; // Use a set to store unique strings
    do {
        result.insert(s); // Insert the current permutation into the set
    } while (next_permutation(s.begin(), s.end())); // Generate the next permutation
    cout << result.size() << endl; // Print the number of unique strings
    for (const auto& str : result) {
        cout << str << endl; // Print each unique string
    }
    return 0;
}
```