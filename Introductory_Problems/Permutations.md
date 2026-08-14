# Permutations
A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
Input
The only input line contains an integer n.
Output
Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example 1
Input:
5

Output:
4 2 5 3 1
Example 2
Input:
3

Output:
NO SOLUTION

***answer*** : arrange the even numbers first followed by the odd numbers. This way, no two adjacent numbers will have a difference of 1.

```cpp code

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if(n ==1)
    {
        cout << 1 << endl;
    }
    else if(n <= 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        for(long long i = 2; i <= n; i += 2)
        {
            cout << i << " ";
        }
        for(long long i = 1; i <= n; i += 2)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;

}