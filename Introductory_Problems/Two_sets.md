# Two Sets

Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
Constraints

1 \le n \le 10^6

Example 1
Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6

Output:
NO

***answer*** : To determine if the numbers from 1 to n can be divided into two sets of equal sum, we first need to calculate the total sum of these numbers. The sum of the first n natural numbers is given by the formula:
S = n * (n + 1) / 2
If S is odd, it is impossible to divide the numbers into two sets of equal sum, and we should output "NO". If S is even, we can proceed to find a way to divide the numbers into two sets.
To divide the numbers into two sets of equal sum, we can use a greedy approach. We will start from the largest number n and keep adding numbers to the first set until the sum of that set reaches half of the total sum S/2. The remaining numbers will automatically form the second set.

```cpp code

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    long long target = sum / 2;
    vector<long long> set1, set2;

    for (long long i = n; i >= 1; --i) {
        if (target >= i) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << set1.size() << endl;
    for (auto num : set1) {
        cout << num << " ";
    }
    cout << endl;

    cout << set2.size() << endl;
    for (auto num : set2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```