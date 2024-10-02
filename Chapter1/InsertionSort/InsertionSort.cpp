#include <iostream>

using namespace std;

void print(int arr[], int size);

int main() {
    // 하나씩 밀기
    {
        int arr[] = { 1, 2, 4, 5, 3, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);

        print(arr, n);

        int i = 4;

        int temp = arr[i];
        for(int j = i; j > 0; j--){
            arr[j] = arr[j-1];
            print(arr, n);
        }
    }
    // 알맞는 위치에 저장
    {
        int arr[] = { 1, 2, 4, 5, 3, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);

        print(arr, n);

        int i = 4;

        int temp = arr[i];
        int j = i;
        for(j; j > 0 && arr[j-1] > temp; j--){
            arr[j] = arr[j-1];
            print(arr, n);
        }
        arr[j] = temp;
        print(arr, n);
    }
    // 구현
    {
        int arr[] = { 8, 3, 2, 5, 1, 2 };
        int n = sizeof(arr) / sizeof(arr[0]);

        print(arr, n);

        for(int i = 1; i < n; i++){
            int temp = arr[i];
            int j = i;
            for(j; j > 0 && arr[j-1] > temp; j--){
                arr[j] = arr[j-1];
                print(arr, n);
            }
            arr[j] = temp;
            print(arr, n);
        }
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}
