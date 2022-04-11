#include <initializer_list>
#include <iostream>
#include <cstring>
#include "classes/classes.cpp"
#define MY_DEBUG

int main() {
    var a;
    a = "proverka";
    var b = " raboty stringa";
    auto c = a+b;
    c.print();
}