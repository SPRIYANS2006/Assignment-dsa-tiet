#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

int main() {
    int r, c, n;
    cout << "Enter number of rows, cols, and non-zero elements: ";
    cin >> r >> c >> n;

    Term sparse[100], transpose[100];

    
    sparse[0].row = r;
    sparse[0].col = c;
    sparse[0].val = n;

    cout << "Enter row, col, val for non-zero elements:\n";
    for (int i = 1; i <= n; i++) {
        cin >> sparse[i].row >> sparse[i].col >> sparse[i].val;
    }

   
    transpose[0].row = sparse[0].col;
    transpose[0].col = sparse[0].row;
    transpose[0].val = sparse[0].val;

    int k = 1;
    for (int i = 0; i < sparse[0].col; i++) {  
        for (int j = 1; j <= n; j++) {
            if (sparse[j].col == i) {
                transpose[k].row = sparse[j].col;
                transpose[k].col = sparse[j].row;
                transpose[k].val = sparse[j].val;
                k++;
            }
        }
    }

   
    cout << "\nTranspose in triplet form:\n";
    for (int i = 0; i <= n; i++) {
        cout << transpose[i].row << " "
             << transpose[i].col << " "
             << transpose[i].val << endl;
    }

    return 0;
}
