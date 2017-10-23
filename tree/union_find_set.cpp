#include <stdlib.h>

typedef struct ufs_t {
    int *parent;
    int size;
} ufs_t;

/*
 * @param[in] n size of array
 * @return ufs_t
 */
ufs_t* ufs_create(int n) {
    ufs_t* ufs = (ufs_t*)malloc(sizeof(ufs_t))
    ufs->parent = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        ufs->parent[i] = -1;
    }
    return ufs;
}

/*
 * @param[in] ufs
 * @return void
 */
void ufs_destroy(ufs_t* ufs) {
    free(ufs->parent);
    free(ufs);
}

/*
 * Find: find the root of set contains x (denotation: set(x))
 * @param[in] ufs
 * @param[in] x target element
 * @return
 */
int ufs_find(ufs_t* ufs, int x) {
    if(ufs->parent[x] < 0) return x;
    return ufs->parent[x] = ufs_find(ufs, ufs->parent[x]); /* optimization: path compression */
}

/*
 * Union: join set(y) to set(x), root of set(x) will be the root of the whole set
 * @param[in] ufs
 * @param[in] x one element
 * @param[in] y another element
 * @return -1 if x and y are already in the same set, otherwise return 0
 */
int ufs_union(ufs_t* ufs, int x, int y) {
    const int rx = ufs_find(ufs, x); /* ufs->parent[rx] is negative, indicating number of elements in set(x) */
    const int ry = ufs_find(ufs, y); /* ufs->parent[ry] is negative, indicating number of elements in set(y) */
    if(rx == ry) return -1;

    ufs->parent[rx] += ufs->parent[ry]; /* ufs->parent[rx] updated to number of elements in whole set */
    ufs->parent[ry] = rx; /* new root of set(y) becomes root of set(x) after joining */
    return 0;
}

/*
 * @param[in] ufs
 * @param[in] x
 *
 */
int ufs_set_size(ufs_t* ufs, int x) {
    const int rx = ufs_find(ufs, x);
    return -ufs->parent[rx]; /* negative -> positive, number of elements in set(x) */
}
