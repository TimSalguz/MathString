#include <initializer_list>
#include <iostream>
#include <cstring>
#define MY_DEBUG

class var {
public:
    char *m_string = new char[0];
    int m_size;


    //КОНСТРУКТОР
    var() {
        m_size = 0;
#ifdef MY_DEBUG
		std::cout << "CONSTRUCTOR" << std::endl;
#endif
    }

    //ДЕСТРУКТОР
    ~var() {
#ifdef MY_DEBUG
		std::cout << "DESTRUCTOR" << std::endl;
#endif
    delete [] m_string;
    }

    //КОНСТРУКТОР КОПИРОВАНИЯ
    var(const var &B){
#ifdef MY_DEBUG
		std::cout << "Copy constructor" << std::endl;
#endif
        m_size = 0;
        expandStringBy(B.m_size);
		for (int i = 0; i < m_size; ++i)
			m_string[i] = B.m_string[i];
	}

        //КОНСТРУКТОР КОПИРОВАНИЯ ДРУГОЙ
    var(const char a[]){
#ifdef MY_DEBUG
		std::cout << "Copy constructor initialisation" << std::endl;
#endif
        m_size = 0;
        int strl = strlen(a);
        std::cout << strl <<std::endl;
        expandStringBy(strl);
        for(int i = 0; i<strl; ++i)
            m_string[i] = a[i];
        std::cout << m_size <<std::endl;
	}

    //ПРИСВАИВАНИЕ СТРОКИ
    var operator=(const char a[]) {
        #ifdef MY_DEBUG
		std::cout << "constchar OPERATOR=" << std::endl;
#endif
        int strl = strlen(a);
        expandStringBy(strl);
        for(int i = 0; i<strl; ++i)
            m_string[i] = a[i];
        return *this;
    }

//ВРОДЕ БЕСПОЛЕЗНЫй
//         var operator=(var& b) {
//         #ifdef MY_DEBUG
// 		std::cout << "var OPERATOR=" << std::endl;
// #endif
//         int strl = b.m_size;
//         expandStringBy(strl);
//         for(int i = 0; i<strl; ++i)
//             m_string[i] = b.m_string[i];
//         return *this;
//     }

void combineStrings(var& b){
    expandStringBy(b.m_size);
    std::cout << "b.m_size = " << b.m_size << std::endl;
    int j = 0;
    for (int i = m_size-b.m_size; i<m_size; ++i, ++j) {
        std::cout << "i = " << i << " j = " << j << std::endl;
        m_string[i] = b.m_string[j];
    }
}

void formatNumberStrings(var b){
    deleteBeginUselessZeroes();
    b.deleteBeginUselessZeroes();
}

var operator+(var& b) {
#ifdef MY_DEBUG
		std::cout << "OPERATOR+" << std::endl;
#endif
    if(IsNumber() && b.IsNumber()){
        std::cout << "ETO NOMERA" <<std::endl;
        formatNumberString();
    }
    else {
        combineStrings(b);
    }
    return *this;

}

    // ПЕЧАТЬ СТРОКИ
    void print() {
        for(int i = 0; i < m_size; ++i){
            std::cout << m_string[i];
        }
        std::cout << std::endl;
    }

    int getSize() {
        return m_size;
    }


private:

    int searchPoint() 
    {
        char b;
        for (int i = 0; i < m_size; ++i) 
        {
            b = m_string[i];
            if (b == 44 || b == 46)
                return i;
        }
        return m_size;
    }

    void expandStringBy(int howMuchExpand){
        m_size+=howMuchExpand;
        char *tempString = new char[m_size];
        for(int i = 0; i <m_size-howMuchExpand; ++i)
            tempString[i] = m_string[i];
        delete[] m_string;
        m_string = tempString;
        std::cout << "string expanded by " << howMuchExpand << std::endl;
    }

    bool IsDigit(int symbolNumber)
        {
            if (m_string[symbolNumber] >= 48 && m_string[symbolNumber] < 58)
                return 1;
            else
                return 0;
        }

    bool IsNumber()
        {
            if (m_string[0] == 44 || m_string[0] == 46 || m_string[m_size-1] == 44 || m_string[m_size-1] == 46)
                return 0;
            int points = 0;
            for (int i = 0; i < m_size; i++)
            {
                if(!IsDigit(i))
                {
                    if (m_string[i] == 44 || m_string[i] == 46)
                    {
                        points++;
                        if(points > 1){
                            std::cout << "ETO NE NUMBER!" <<std::endl;
                            return 0;
                        }
                            
                    }
                    else {
                        std::cout << "ETO NE NUMBER!" <<std::endl;
                        return 0;
                    }
                }
            }
            std::cout << "ETO NUMBER!" <<std::endl;
            return 1;
        }
};

int main() {
    var a;
    a = "proverka";
    var b = " raboty stringa";
    auto c = a+b;
    c.print();
}