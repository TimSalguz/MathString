#include <initializer_list>
#include <iostream>
#include <cstring>
#include "classes/classes.cpp"
#define MY_DEBUG

int main() {
    intvar a;
    a = "99999999345";
    intvar b = "9999345";
    auto c = a+b;
    c.print();
}