#include <iostream>

using namespace std;

void recurFunc(int count);

void recurFunc(int count){
    if (count == 0){
        return;
    }

    cout << count << endl;

    recurFunc(count - 1);
}
