
/*Given a string, reverse it using STACK. For example “DataStructure” should be output as
“erutcurtSataD.” */
// time complexity O(n)
// space complexity O(n)
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str ="DataStructure";
    stack<char> s;
    for(int i=0 ;i< str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    cout << "Reversed: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}
