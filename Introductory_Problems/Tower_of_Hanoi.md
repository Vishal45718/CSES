# Tower of Hanoi

The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.
The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.
Input
The only input line has an integer n: the number of disks.
Output
First print an integer k: the minimum number of moves.
After this, print k lines that describe the moves. Each line has two integers a and b: you move a disk from stack a to stack b.
Constraints

1 \le n \le 16

Example
Input:
2

Output:
3
1 2
1 3
2 3

***idea*** : To solve this problem, we can use a recursive approach. The minimum number of moves required to solve the Tower of Hanoi problem with n disks is given by the formula 2^n - 1.

The recursive solution involves moving n-1 disks from the source stack to the auxiliary stack, then moving the nth disk to the destination stack, and finally moving the n-1 disks from the auxiliary stack to the destination stack.

```cpp code

#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    hanoi(n, 1, 3, 2);
    return 0;
}

```