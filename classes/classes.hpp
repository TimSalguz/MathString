#pragma once
#include <iostream>

class var {
public:
    char *m_string = new char[0];
    int m_size;

    var();                                       //КОНСТРУКТОР

    ~var();                                      //ДЕСТРУКТОР

    var(const var &B);                           //КОНСТРУКТОР КОПИРОВАНИЯ

    var(const char a[]);                         //КОНСТРУКТОР КОПИРОВАНИЯ ДРУГОЙ

    var operator=(const char a[]);               //ПРИСВАИВАНИЕ СТРОКИ

    var operator+(var& b);                       //ОПЕРАТОР СЛОЖЕНИЯ

    void combineStrings(var& b);                 //ОБЪЕДИНЕНИЕ СТРОК

    void print();                                //ПЕЧАТЬ СТРОКИ

    int getSize();                               //ПОЛУЧИТЬ РАЗМЕР СТРОКИ

private:

    int searchPoint();                           //ВЫДАЕТ ПОЛОЖЕНИЕ ТОЧКИ В СТРОКЕ

    void expandStringBy(int howMuchExpand);      //УВЕЛИЧИВАЕТ СТРОКУ

    bool IsDigit(int symbolNumber);              //ЦИФРА ЛИ

    bool IsNumber();                             //ЧИСЛО ЛИ
};