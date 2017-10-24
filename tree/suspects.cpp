#include <stdio.h>
#include "union_find_set.c"

#define MAXN 30000

int main() {
    int n, m, k;
    cin >> n >> m; /* n, number of students; m, number of societies */
    while(n > 0) {
        ufs_t* ufs = ufs_create(MAXN);
        while(m--) {
            int x, y;
            int rx, ry;
            cin >> k; /* k, number of students in this society */

            k--;
            cin >> x; /* first student */
            rx = ufs_find(ufs, x);
            while(k--) {
                cin >> y; /* union one next student every time */
                ry = ufs_find(ufs, y);
                ufs_union(ufs, rx, ry);
            }
        }
        cout << ufs_set_size(ufs, 0); /* No. 0 student is suspect */
        ufs_destroy(ufs);
    }
    return 0;
}
