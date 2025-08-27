#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

int main() {
    int r, c, n1, n2;
    cout << "Enter number of rows and columns of matrices: ";
    cin >> r >> c;

    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> n1;
    Term A[100];
    A[0].row = r;
    A[0].col = c;
    A[0].val = n1;

    cout << "Enter row col val for Matrix A:\n";
    for (int i = 1; i <= n1; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    cout << "Enter number of non-zero elements in Matrix B: ";
    cin >> n2;
    Term B[100];
    B[0].row = r;
    B[0].col = c;
    B[0].val = n2;

    cout << "Enter row col val for Matrix B:\n";
    for (int i = 1; i <= n2; i++) {
        cin >> B[i].row >> B[i].col >> B[i].val;
    }

    Term C[200]
    C[0].row = r;
    C[0].col = c;

    int i = 1, j = 1, k = 1;

    
    while (i <= n1 && j <= n2) {
        if (A[i].row < B[j].row || 
           (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        else if (B[j].row < A[i].row || 
                (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        }
        else { 
            C[k].row = A[i].row;
            C[k].col = A[i].col;
            C[k].val = A[i].val + B[j].val;
            if (C[k].val != 0)  
                k++;
            i++; j++;
        }
    }

    
    while (i <= n1) C[k++] = A[i++];
    while (j <= n2) C[k++] = B[j++];

    C[0].val = k - 1;  

   
    cout << "\nResultant Matrix after Addition (Triplet form):\n";
    for (int x = 0; x <= C[0].val; x++) {
        cout << C[x].row << " "
             << C[x].col << " "
             << C[x].val << endl;
    }

    return 0;
}
