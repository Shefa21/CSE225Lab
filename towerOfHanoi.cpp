#include <iostream>
using namespace std;

// Function to move disks from source peg to destination peg using auxiliary peg
// n: number of disks to move
// src: source peg
// des: destination peg
// aux: auxiliary peg
void towerOfHanoi(int n, char src, char des, char aux) {
    // Base case: If there's only one disk to move
    if (n == 1) {
        // Move the disk directly from source peg to destination peg
        cout << "Move disk 1 from " << src << " to " << des << endl;
        return;
    }

    // Move (n-1) disks from source to auxiliary peg using destination peg as an auxiliary
    towerOfHanoi(n - 1, src, aux, des);

    // Move the largest disk from source peg to destination peg
    cout << "Move disk " << n << " from " << src << " to " << des << endl;

    // Move (n-1) disks from auxiliary peg to destination peg using source peg as an auxiliary
    towerOfHanoi(n - 1, aux, des, src);
}

int main() {
    int n = 5; // Number of disks

    // Call towerOfHanoi function to solve the problem for n disks
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
