#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

void transpose(Term A[], Term T[]) {
    T[0].row = A[0].col;
    T[0].col = A[0].row;
    T[0].val = A[0].val;

    int n = A[0].val;
    int k = 1;

    for (int i = 0; i < A[0].col; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[j].col == i) {
                T[k].row = A[j].col;
                T[k].col = A[j].row;
                T[k].val = A[j].val;
                k++;
            }
        }
    }
}


void multiply(Term A[], Term B[], Term C[]) {
    Term BT[200];
    transpose(B, BT);  

    C[0].row = A[0].row;
    C[0].col = B[0].col;
    C[0].val = 0;

    int k = 1;

    
    for (int i = 0; i < A[0].row; i++) {
       
        int rowA[200], valA[200], na = 0;
        for (int j = 1; j <= A[0].val; j++) {
            if (A[j].row == i) {
                rowA[na] = A[j].col;
                valA[na] = A[j].val;
                na++;
            }
        }

        if (na == 0) continue; 
        
        for (int j = 0; j < BT[0].row; j++) {
            int rowB[200], valB[200], nb = 0;
            for (int l = 1; l <= BT[0].val; l++) {
                if (BT[l].row == j) {
                    rowB[nb] = BT[l].col;
                    valB[nb] = BT[l].val;
                    nb++;
                }
            }

            if (nb == 0) continue;

            
            int sum = 0;
            int x = 0, y = 0;
            while (x < na && y < nb) {
                if (rowA[x] == rowB[y]) {
                    sum += valA[x] * valB[y];
                    x++; y++;
                }
                else if (rowA[x] < rowB[y]) x++;
                else y++;
            }

            if (sum != 0) {
                C[k].row = i;
                C[k].col = j;
                C[k].val = sum;
                k++;
            }
        }
    }

    C[0].val = k - 1; 
}

int main() {
    int r1, c1, n1, r2, c2, n2;
    cout << "Enter rows, cols and non-zero elements of Matrix A: ";
    cin >> r1 >> c1 >> n1;

    Term A[200];
    A[0].row = r1;
    A[0].col = c1;
    A[0].val = n1;

    cout << "Enter row col val for Matrix A:\n";
    for (int i = 1; i <= n1; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    cout << "Enter rows, cols and non-zero elements of Matrix B: ";
    cin >> r2 >> c2 >> n2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!\n";
        return 0;
    }

    Term B[200];
    B[0].row = r2;
    B[0].col = c2;
    B[0].val = n2;

    cout << "Enter row col val for Matrix B:\n";
    for (int i = 1; i <= n2; i++) {
        cin >> B[i].row >> B[i].col >> B[i].val;
    }

    Term C[400];
    multiply(A, B, C);

    cout << "\nResultant Matrix after Multiplication (Triplet form):\n";
    for (int i = 0; i <= C[0].val; i++) {
        cout << C[i].row << " " << C[i].col << " " << C[i].val << endl;
    }

    return 0;
}
