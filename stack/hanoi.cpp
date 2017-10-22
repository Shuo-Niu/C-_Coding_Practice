#include <stdio.h>
#include <iostream>
using namespace std;
/*
 * @param[in] n number of levels
 * @param[in] x source tower
 * @param[in] y assist tower
 * @param[in] z destination tower
 * @return void
 */
void hanoi(int n, char x, char y, char z) {
    if(n == 1) {
        cout << n << " from " << x << " to " << z << "\n";
        return;
    } else {
        hanoi(n-1, x, z, y);
        cout << n << " from " << x << " to " << z << "\n";
        hanoi(n-1, y, x, z);
    }
}

int main() {
    int n;
    cout << "Number of levels: ";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
