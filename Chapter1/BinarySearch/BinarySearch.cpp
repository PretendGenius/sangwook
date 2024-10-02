#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int num);
void print(int arr[], int size, int left, int right);

int main() {
    int arr[] = { 1,2,2,4,4,6,7,8,8,9,10,13,15,20,23,25,27,30,33,34,40,41,44 };
    int n = sizeof(arr)/sizeof(arr[0]);

    binarySearch(arr, n, 7);
}

int binarySearch(int arr[], int size, int num){
    int left = 0;
    int right = size - 1;
    while(left <= right){
        print(arr, size, left, right);
        int middle = (right + left)/2;
        cout << "middle " << middle << endl;

        if(arr[middle] > num){
            right = middle - 1;
            cout << "right " << right << endl;
        } else if(arr[middle] < num) {
            left = middle + 1;
            cout << "left " << left << endl;
        } else {
            cout << "Found " << middle << endl;
            return middle;
        }
    }

    cout << "Not Found " << endl;
    return -1;
} 

void print(int arr[], int size, int left, int right){
    for(int i = left; i <= right; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
