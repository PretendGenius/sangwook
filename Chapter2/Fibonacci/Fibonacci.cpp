#include <iostream>

using namespace std;

int recursionFibonacci(int num);
int fibonacci(int num);

int recursionFibonacci(int num){
    if(num == 0){
        return 0;
    } else if(num == 1){
        return 1;
    } else {
        return recursionFibonacci(num-1) + recursionFibonacci(num-2);
    }
}

int fibonacci(int num){
    if(num == 0){
        return 0;
    } else if(num == 1){
        return 1;
    } else {
        int x = 0;
        int y = 1;
        int fibonacci = 0;

        for(int i = 1; i <= num; i++){
            fibonacci = x + y;
            x = y;
            y = fibonacci;
        }

        return fibonacci;
    }
}
