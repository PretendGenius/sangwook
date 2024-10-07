#pragma once

#include <iostream>
#include <algorithm>
#include <cassert>

class MyString{
    public:
    MyString();
    MyString(const char* init);
    MyString(const MyString& str);
    ~MyString();

    bool isEmpty();
    bool isEqual(const MyString& str);
    int length();
    void resize(int new_size);

    MyString substr(int start, int num);
    MyString concat(MyString app_str);
    MyString insert(MyString t, int start);

    int find(MyString pat);
    void print();

    private:
    char* str_ = nullptr;
    int size_ = 0;
};