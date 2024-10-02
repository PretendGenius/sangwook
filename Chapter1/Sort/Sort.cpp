#include <iostream>

using namespace std;

void swap(int& a, int &b);
bool checkSorted(int arr[], int size);
int main() {
    //swap
    {
        int a = 3;
        int b = 2;

        swap(a, b);

        cout << a << " " << b << endl;
    }

    {
        int arr[] = { 3, 2 };
        cout << arr[0] << " " << arr[1] << endl;
        if(arr[0] > arr[1]){
            swap(arr[0], arr[1]);
        }
        cout << arr[0] << " " << arr[1] << endl;
    }

    {
        cout << boolalpha;
        for(int j = 0; j < 5; j ++) {
            for(int i = 0; i < 5; i++) {
                int arr[] = {i, j};
                cout << arr[0] << " " << arr[1] << " " << checkSorted(arr, 2) << endl;
            }
        }
    }

    {
        for(int j = 0; j < 5; j ++) {
            for(int i = 0; i < 5; i++) {
                int arr[] = {i, j};
                if(arr[0] > arr[1]){
                    swap(arr[0], arr[1]);
                }
                cout << arr[0] << " " << arr[1] << " " << checkSorted(arr, 2) << endl;
            }
        }
    }
    //3개 정렬
    {
        for(int k = 0; k < 3; k++){
            for(int j = 0;  j < 3; j++) {
                for(int i = 0; i < 3; i++) {
                    int arr[3] = { i, j, k };
                    int size = sizeof(arr) / sizeof(arr[0]);

                    for (int e = 0; e < size; e++) {
                        cout << arr[e] << " " << flush;
                    }

                    cout << " -> " << flush;
                    
                    for (int l = 0; l < size; l++) {
                        int min = arr[l];
                        int minIndex = l;
                        for (int z = l; z < size; z++){
                            if(arr[z] <= min){
                                min = arr[z];
                                minIndex = z;
                            }
                        }
                        int temp = arr[minIndex];
                        arr[minIndex] = arr[l];
                        arr[l] = temp;
                    }


                    for (int e = 0; e < size; e++) {
                        cout << arr[e] << " " << flush;
                    }

                    cout << boolalpha;
                    cout << checkSorted(arr, size);
                    cout << endl;
                }
            }
        }
    }
    
    return 0;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

bool checkSorted(int arr[], int size){
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}
