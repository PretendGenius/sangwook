#include <iostream>

using namespace std;

void print(int arr[], int size);

int main() {
    int arr[] = { 8, 3, 2, 5, 1, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);

    {
        for(int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swapped = true;
                }
            }
            if(swapped == false){
                break;
            }
        }
    }

    print(arr, n);

    return 0;
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}
