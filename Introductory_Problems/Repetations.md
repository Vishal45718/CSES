You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.
Constraints

1 \le n \le 10^6

Example
Input:
ATTCGGGA

Output:
3


```cpp code

#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;

   cin >> s;
   int max_length = 1, current_length = 1;

   for(int i=1; i<s.size(); i++)
   {
       if(s[i] == s[i-1])
       {
           current_length++;
           max_length = max(max_length, current_length);
       }
       else
       {
           current_length = 1;
       }
   }

   cout << max_length << endl;

   return 0;

}