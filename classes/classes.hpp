#pragma once
#include <iostream>

class drobvar {
public:
    intvar number, numerator, denumenator;

    drobvar();

    ~drobvar();

    drobvar(const drobvar &B);

    drobvar operator=(intvar A);
};


class intvar {
public:
    char *m_string = new char[0];
    int m_size;

    intvar();                                       //КОНСТРУКТОР

    ~intvar();                                      //ДЕСТРУКТОР

    intvar(const intvar &B);                           //КОНСТРУКТОР КОПИРОВАНИЯ

    intvar(const char a[]);                         //КОНСТРУКТОР КОПИРОВАНИЯ ДРУГОЙ

    intvar operator=(const char a[]);               //ПРИСВАИВАНИЕ СТРОКИ

    intvar operator+(intvar& b);                       //ОПЕРАТОР СЛОЖЕНИЯ

    void intSum(intvar& a, intvar& b);

    void combineStrings(intvar& a, intvar& b);         //ОБЪЕДИНЕНИЕ СТРОК

    void print();                                //ПЕЧАТЬ СТРОКИ

    int getSize();                               //ПОЛУЧИТЬ РАЗМЕР СТРОКИ

private:

    void add1toBegin(int whatAdd);

    int searchPoint();                           //ВЫДАЕТ ПОЛОЖЕНИЕ ТОЧКИ В СТРОКЕ

    void expandStringBy(int howMuchExpand);      //УВЕЛИЧИВАЕТ РАЗМЕР СТРОКИ

    bool isDigit(int symbolNumber);              //ЦИФРА ЛИ

    bool isNumber();                             //ЧИСЛО ЛИ

    bool isFractional();                         //ДРОБНОЕ ЛИ
    
    bool isComplex();                            //КОМПЛЕКСНОЕ ЛИ

    void formatNumberStrings(intvar& b);

    bool beginIsFormated(intvar& b);
};