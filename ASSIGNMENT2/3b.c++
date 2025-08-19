#include<iostream>
using namespace std;
int missingelement(int arr[], int n){
    int start =0;
    int end = 5;
    
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] != mid +1){
            if (arr[mid  -1] == mid){
                   cout << "missing element is:" << mid +1<< " at index: " << mid << endl;
            }
              end = mid -1;
        }
        else{
            start = mid +1;
        }
               
    }
    return n;
}
int main(){
int arr[] = {1, 2, 3, 4, 5 ,7};
int n = 6;
missingelement(arr, n);

    return 0;
}
