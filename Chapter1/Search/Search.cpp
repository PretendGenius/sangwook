#include <iostream>

using namespace std;

int count(int arr[], int size, int num);
int sequentialSearch(int arr[], int size, int num);
int sortedCountHelper(int arr[], int n, int x, int start);
int sortedCount(int arr[], int size, int num);
void insertionSort(int arr[], int size);
void print(int arr[], int size);

int main() {
    int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2 ,1 ,1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Count 9 = " << count(arr, n, 9) << endl;
    cout << "Count 2 = " << count(arr, n, 2) << endl;
    cout << "Count 8 = " << count(arr, n, 8) << endl;
    cout << "Count 1 = " << count(arr, n, 1) << endl;
    cout << endl;

    cout << "Search 2 = " << sequentialSearch(arr, n, 2) << endl;
    cout << "Search 5 = " << sequentialSearch(arr, n, 5) << endl;
    cout << "Search 9 = " << sequentialSearch(arr, n, 9) << endl;
    cout << "Search 1 = " << sequentialSearch(arr, n, 1) << endl;
    cout << endl;

    insertionSort(arr, n);
    print(arr, n);

    cout << "Sorted Count 9 = " << sortedCount(arr, n , 9) << endl;
    cout << "Sorted Count 2 = " << sortedCount(arr, n , 2) << endl;
    cout << "Sorted Count 8 = " << sortedCount(arr, n , 8) << endl;
    cout << "Sorted Count 1 = " << sortedCount(arr, n , 1) << endl;
}

int count(int arr[], int size, int num){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == num){
            count++;
        }
    }
    return count;
}

int sequentialSearch(int arr[], int size, int num){
    for(int i = 0; i < size; i++){
        if(arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int sortedCountHelper(int arr[], int size, int num, int start){
    int count = 0;
    for(int i = start; i < size; i++){
        if(arr[i] == num){
            count ++;
        } else {
            break;
        }
    }
    return count;
}

int sortedCount(int arr[], int size, int num){
    int i = sequentialSearch(arr, size, num);

    if (i == -1) return 0;
    return sortedCountHelper(arr, size, num, i + 1) + 1;
}

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i;
        for(j; j > 0 && arr[j-1] > key; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = key;
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
