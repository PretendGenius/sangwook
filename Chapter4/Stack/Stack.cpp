#include <iostream>
#include "Stack.h"

int main() {
    using namespace std;

    Stack<char> s;

    s.push('A');
    s.print();

    s.push('B');
    s.print();

    s.push('C');
    s.print();

    cout << "TOP = " << s.top() << endl;

    s.pop();
    s.print();

    cout << "Top = " << s.top() << endl;

    s.pop();
    s.print();

    s.push('E');
    s.print();

    s.pop();
    s.print();

    cout << "Top = " << s.top() << endl;
    
    return 0;
}