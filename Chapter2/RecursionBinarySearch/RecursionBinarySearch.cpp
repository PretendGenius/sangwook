#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int num);
int recursionBinarySearch(int arr[], int left, int right, int num);
void print(int arr[], int size, int left, int right);

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << binarySearch(arr, n, -2) << endl;
    cout << recursionBinarySearch(arr, 0, n-1, -2) << endl;

    return 0;
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

int recursionBinarySearch(int arr[], int left, int right, int num){
    int middle = (right + left)/2;
    if(arr[middle] > num){
        recursionBinarySearch(arr, left, middle - 1, num);
    } else if(arr[middle] < num) {
        recursionBinarySearch(arr, middle + 1, right, num);
    } else {
        return middle;
    }
}

void print(int arr[], int size, int left, int right){
    for(int i = left; i <= right; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
