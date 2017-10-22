#include <stack>
#include <cstdio>
#include <iostream>
using namespace std;
/*
 * @param[in] n decimal integer n
 * @param[in] d base d, d <= 16
 * @return void
 */
 void convert_base(int n, const int d) {
    stack<int> s;
    int e;

    while(n != 0) {
        e = n % d;
        s.push(e);
        n /= d;
    }
    while(!s.empty()) {
        e = s.top();
        s.pop();
        printf("%X", e);
    }
    return;
 }

 const int MAXN = 64; // maximum length of stack
 int stack2[MAXN];
 int top = -1;
/*
 * Using array as stack is more efficient if the maximum length is known.
 * @param[in] n decimal integer n
 * @param[in] d base d, d <= 16
 * @return void
 */
 void convert_base2(int n, int d) {
     int e;

     while(n != 0) {
        e = n % d;
        stack2[++top] = e;
        n /= d;
     }
     while(top >= 0) {
        e = stack2[top--];
        printf("%X", e);
     }
     return;
 }

/*
 * @param[in] s d-base integer
 * @param[in] d base d, d <= 16
 * @return decimal integer
 */
 int restore(const char s[MAXN], const int d) {
     int result = 0;
     int digit;

     for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= '0' && s[i] <= '9') digit = s[i] - '0';
        else if(s[i] >= 'A' && s[i] <= 'F') digit = s[i] - 'A' + 10;
        else digit = s[i] - 'a' + 10;

        result = result * d + digit;
     }
     return result;
 }

 int main() {
     convert_base(30,16);
     cout << endl;
     convert_base2(30, 16);
     int p = restore("1E",16);
     cout << endl << p;
     return 0;
 }
