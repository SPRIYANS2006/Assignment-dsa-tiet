// Write a program for the evaluation of a Postfix expression.
// time complexity O(n)
// space complexity O(n)
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int evaluatePostfix(string str) {
    stack<int> s;
    for (int i=0; i< str.size();i++) {
        char ch = str[i];
        if (isdigit(ch)) s.push(ch - '0');
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string str;
    cout << "Enter Postfix: ";
    cin >> str;
    cout << "Evaluation: " << evaluatePostfix(str) << endl;
    return 0;
}
