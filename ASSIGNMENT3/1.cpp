/* 
Menu driven program demonstrating stack operations using array:
Operations: 
(i) push() - O(1) 
(ii) pop() - O(1) 
(iii) isEmpty() - O(1) 
(iv) isFull() - O(1) 
(v) display() - O(n) 
(vi) peek() - O(1)
*/
 
#include<iostream>
using namespace std;

class stack {
public:
    int *arr;
    int top;
    int size;

    stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            cout << "Popped: " << arr[top] << endl;
            top--;
        } else {
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
        if (top >= 0)
            return arr[top];
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (top == size - 1) {
            return true;
        } else {
            return false;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}; 

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    stack s(n);  

    int choice, val;
    do {
        cout << "\n1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n0.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter value: "; 
                cin >> val; 
                s.push(val); 
                break;
            case 2: 
                s.pop(); 
                break;
            case 3: 
                cout << (s.isEmpty() ? "Yes\n" : "No\n"); 
                break;
            case 4: 
                cout << (s.isFull() ? "Yes\n" : "No\n"); 
                break;
            case 5: 
                s.display(); 
                break;
            case 6: 
                cout << "Top element: " << s.peek() << endl; 
                break;
            case 0: 
                cout << "Exiting...\n"; 
                break;
            default: 
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
