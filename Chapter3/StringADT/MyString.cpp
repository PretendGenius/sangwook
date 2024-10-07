#include <iostream>
#include "MyString.h"

using namespace std;

MyString::MyString(){
    str_ = nullptr;
    size_ = 0;
}

MyString::MyString(const char* init){
    size_ = 0;
    while (init[size_] != '\0'){
        size_++;
    }

    str_ = new char[size_];
    memcpy(str_, init, size_);
}

MyString::MyString(const MyString& str){
    size_ = str.size_;
    str_ = new char[size_];
    memcpy(str_, str.str_, size_);
}

MyString::~MyString(){
    if(str_ != nullptr) {
        delete[] str_;
        str_ = nullptr;
        size_ = 0;
    }
}

bool MyString::isEmpty(){
    return length() == 0;
}

bool MyString::isEqual(const MyString& str){
    if(size_ != str.size_){
        return false;
    }
    for(int i = 0; i < size_; i++){
        if(str_[i] != str.str_[i]){
            return false;
        } 
    }
    return true;
}

int MyString::length(){
    return size_;
}

void MyString::resize(int new_size){
    if (new_size != size_){
        char* new_str = new char[new_size];

        for (int i = 0; i < (new_size < size_ ? new_size : size_); i++){
            new_str[i] = str_[i];
        }

        delete[] str_;
        str_ = new_str;
        size_ = new_size;
    }
}

MyString MyString::substr(int start, int num){
    char* new_str = new char[num];
    MyString temp;
    temp.size_ = num;
    temp.str_ = new char[size_];
    for(int i = 0; i < num; i++){
        new_str[i] = str_[start + i];
    }
    memcpy(temp.str_, new_str, num);

    return temp;
}

MyString MyString::concat(MyString app_str){
    int new_size = size_ + app_str.size_;
    MyString temp;
    temp.size_ = new_size;
    temp.str_ = new char[new_size];
    for(int i = 0; i < new_size; i++){
        if(i < size_){
            temp.str_[i] = str_[i];
        } else {
            temp.str_[i] = app_str.str_[i - size_];
        }
    }

    return temp;
}

MyString MyString::insert(MyString t, int start){
    MyString temp;

    temp.resize(size_ + t.size_);

    for(int i = 0; i < start; i++){
        temp.str_[i] = str_[i];
    }

    for(int i = start; i < start + t.size_; i++){
        temp.str_[i] = t.str_[i - start];
    }

    for(int i = start + t.size_; i < size_ + t.size_; i++){
        temp.str_[i] = str_[i - t.size_];
    }

    return temp;
}

int MyString::find(MyString pat){
    int index = -1;
    for(int i = 0; i <= length() - pat.length(); i ++){
        if(this -> substr(i, pat.length()).isEqual(pat)){
            index = i;
        }
    }
    return index;
}

void MyString::print()
{
    for (int i = 0; i < size_; i++){
        cout << str_[i];
    }
    cout << endl;
}
int main() {
    {
        MyString str1("hi hay he hel hello llo ello el el o!");
        str1.print();
    }

    {
        MyString str1("hi hay he hel hello llo ello el el o!");
        cout << str1.find(MyString("hell")) << endl;

        cout << "Found at " << MyString("ABCDEF").find(MyString("A")) << endl;
        cout << "Found at " << MyString("ABCDEF").find(MyString("AB")) << endl;
        cout << "Found at " << MyString("ABCDEF").find(MyString("CDE")) << endl;
        cout << "Found at " << MyString("ABCDEF").find(MyString("EF")) << endl;
        cout << "Found at " << MyString("ABCDEF").find(MyString("EFG")) << endl;
        cout << "Found at " << MyString("ABCDEF").find(MyString("EFGHIJ")) << endl;
    }

    {
        MyString str1("hi hay he hel hello llo ello el el o!");
        MyString str2 = str1;
        str2.print();
    }

    {
        MyString str3("Hello, world!");
        cout << boolalpha;
        cout << str3.isEqual(MyString("Hello, world!")) << endl;
        cout << str3.isEqual(MyString("Hay, world!")) << endl;
    }

    {
        MyString str4("ABCDE");
        for (int i = 0; i <= str4.length(); i++){
            MyString str5 = str4.insert(MyString("123"), i);
            str5.print();
        }
    }

    {
        MyString str("ABCDEFGHIJ");

        str.substr(3, 4).print();
    }

    {
        MyString str1("Hello, ");
        MyString str2("world!");

        MyString str3 = str1.concat(str2);

        str3.print();
    }
     return 0;
}