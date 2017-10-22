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
                cout << s << " ";
            }
        }
        cout << endl;
    }
}

/*
 * Another way to print Pascal Triangle - using a vector, like using an ArrayList in Java
 */
void pascal_triangle2(const int n) {
    vector<int> row;

    for(int i = 0; i < n; i++) {
        row.push_back(1);
        for(int j = i-1; i > 1 && j >= 1; j--) {
            row.insert(row.begin()+j, row[j]+row[j-1]);
            row.erase(row.begin()+j+1);
        }

        for(int j = 0; j < row.size(); j++) {
            cout << row[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    pascal_triangle(5);
    cout << endl;
    pascal_triangle2(5);
    return 0;
}
