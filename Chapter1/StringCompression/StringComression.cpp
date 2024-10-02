#include <iostream>

using namespace std;

void insertionSort(char arr[], int size);
void print(char arr[], int size);

int main(){
    char arr[] = "ababcdfdceeedag";
    int n = sizeof(arr)/sizeof(arr[0]) - 1;

    {
        int table[26] = {0};
        for(int i = 0; i < n; i++){
            table[int(arr[i])-97]++;
        }
        for(int i = 0; i < 26; i++){
            if(table[i] != 0){
                cout<< char(i+97) << table[i];
            }
        }
        cout << endl;
    }

    {
        insertionSort(arr, n);

        cout << arr << endl;

        char c = arr[0];
        int count = 1;
        cout << c;

        for(int i = 1; i < n; i++){
            if (arr[i] == c){
                count ++;
            } else {
                cout << count;
                c = arr[i];
                cout << c;
                count = 1;
            }
        }

        cout << count << endl;
    }
}

void insertionSort(char arr[], int size){
    for(int i = 1; i < size; i++){
        char key = arr[i];
        int j = i;
        for(j; j > 0 && arr[j-1] > key; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = key;
    }
}

void print(char arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
