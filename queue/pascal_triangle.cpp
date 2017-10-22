#include <queue>
#include <iostream>
using namespace std;
/*
 * @param[in] n number of levels
 * @return void
 */
void pascal_triangle(const int n) {
    queue<int> q;
    q.push(1);

    for(int i = 0; i < n; i++) {
        int s = 0;
        q.push(s);

        for(int j = 0; j < i+2; j++) {
            int t;
            int tmp;
            t = q.front();
            q.pop();
            tmp = s + t;
            q.push(tmp);
            s = t;
            if(j != i+1) {
                cout << s;
            }
        }
        cout << endl;
    }
}

int main() {
    pascal_triangle(5);
    return 0;
}
