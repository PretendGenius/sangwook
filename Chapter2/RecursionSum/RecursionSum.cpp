#include <iostream>

using namespace std;

int sum(int arr[], int size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum;
}

int recursionSum(int arr[], int size){
    if(size <= 0){
        return 0;
    }
    return recursionSum(arr, size - 1) + arr[size - 1];
}
