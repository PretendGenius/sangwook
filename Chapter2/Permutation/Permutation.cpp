#include <iostream>

using namespace std;

void recursionPermutation(char arr[], int left, int right);
void swap(int& a, int& b);

void recursionPermutation(char arr[], int left, int right){
    if(left == right){
        for(int i = 0; i<=right; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        for(int i = left; i <= right; i++){
            swap(arr[left], arr[i]);
            recursionPermutation(arr, left + 1, right);
            swap(arr[left], arr[i]);
        }
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
