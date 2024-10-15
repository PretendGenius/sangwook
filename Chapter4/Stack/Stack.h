#pragma once

#include <cassert>
#include <iostream>

template<typename T>
class Stack {
    public :
    Stack(int capacity = 1){
        assert(capacity > 0);
        resize(capacity);
    }

    void resize(int new_capacity){
        T* new_stack = new T[new_capacity];
        memcpy(new_stack, stack_, sizeof(T) * size());
        if (stack_) delete[] stack_;
        stack_ = new_stack;
        capacity_ = new_capacity;
    }

    bool isEmpty() const {
        if(top_ < 0) {
            return true;
        }
        return false;
    }

    int size() const {
        return top_ + 1;
    }

    void print() {
        using namespace std;

        for (int i = 0; i < size(); i++) {
            cout << stack_[i] << " ";
        }
        cout << endl;
    }

    T& top() const {
        assert(!isEmpty());

        return stack_[top_];
    }

    void push(const T& item) {
        if (top_ == capacity_ - 1){
            resize(capacity_ * 2);
        }
        stack_[++top_] = item;
    }

    void pop() {
        --top_;
    }
    private :
    T* stack_ = nullptr;
    int top_ = -1;
    int capacity_ = 0;
};