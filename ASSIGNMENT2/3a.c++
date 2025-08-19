#include<iostream>
using namespace std;
int linearsearch(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << "missing number is :"<< i + 1 << endl;
            return i+1;
        }
        
    }
   cout << "Missing number is: " << n << endl;
    return n;
}
int main(){
    int arr[] = {1, 2, 3, 5, 6 ,7};
int n = 6;
linearsearch(arr, n);


    return 0;
}
