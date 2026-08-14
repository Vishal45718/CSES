# Digit Queries

Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...
Your task is to process q queries of the form: what is the digit at position k in the string?
Input
The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.
Output
For each query, print the corresponding digit.
Constraints

1 \le q \le 1000
1 \le k \le 10^{18}

Example
Input:
3
7
19
12

Output:
7
4
1

*** idea *** :

For a digit length d:

first number = 10^(d-1)
count of numbers = 9 * 10^(d-1)
total digits contributed
9×10^d−1×d

Digits	Numbers	Total digits
1	9	9
2	90	180
3	900	2700
4	9000	36000
5	90000	450000



- check which block od digits it is in (no of digits contributed by 1-digit numbers, 2-digit numbers, etc.)
- then each number contributes d digits, so we can find the number and then the digit within that number.
number_index = (k-1)/d

number_index = (k-1)/d
where start = 10^(d-1)

Inside this number,digit_index = (k-1)%d

``` cpp code

#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using int128 = __int128_t;

int main()
{
    int q; 
    cin >> q;

    while(q--)
    {
        int64 k;
        cin >> k;

        int64 digits = 1;
        int64 start = 1;

        while(true)
        {
            i128 cnt = (i128)9 * start * digits;

            if(k > cnt)
            {
                k -= (int64)cnt;
                digits++;
                start *= 10;
            }
            else
            {
                break;
            }

            int64 number = start + (k - 1) / digits;
        int64 idx = (k - 1) % digits;
            
            string s = to_string(number);
            cout << s[idx] << endl;
            
        }

    }
    return 0;
}
