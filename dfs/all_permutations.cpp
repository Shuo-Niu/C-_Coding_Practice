#include <iostream>
using namespace std;

#define N 4
int history[N];

void dfs(int n) {
    if(n == N) {
        for(int i = 0; i < N; i++) {
            cout << history[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < N; i++) {
        int ok = 1;
        for(int j = 0; j < n; j++) {
            if(history[j] == i+1) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            history[n] = i+1;
            dfs(n+1);
        }
    }
}

int main() {
    dfs(0);
    return 0;
}
