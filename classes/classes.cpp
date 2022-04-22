#include "classes.hpp"
intvar::intvar() {
        m_size = 0;
#ifdef MY_DEBUG
        std::cout << "CONSTRUCTOR" << std::endl;
#endif
}


intvar::~intvar() {
#ifdef MY_DEBUG
    std::cout << "DESTRUCTOR" << std::endl;
#endif
delete [] m_string;
}

intvar::intvar(const intvar &B){
#ifdef MY_DEBUG
    std::cout << "Copy constructor" << std::endl;
#endif
m_size = 0;
expandStringBy(B.m_size);
for (int i = 0; i < m_size; ++i)
    m_string[i] = B.m_string[i];
}

intvar::intvar(const char a[]){
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

intvar intvar::operator=(const char a[]) {
#ifdef MY_DEBUG
    std::cout << "constchar OPERATOR=" << std::endl;
#endif
    int strl = strlen(a);
    expandStringBy(strl);
    for(int i = 0; i<strl; ++i)
        m_string[i] = a[i];
    return *this;
}



intvar intvar::operator+(intvar& b) {
#ifdef MY_DEBUG
		std::cout << "OPERATOR+" << std::endl;
#endif
    intvar c;
    if(isNumber() && b.isNumber()){
        std::cout << "ETO NOMERA" <<std::endl;
        c.intSum(*this, b);
    }
    else {
        c.combineStrings(*this,b);
    }
    return c;
}

void intvar::intSum(intvar& a,intvar& b) {
    bool mind = 0;
    intvar other;
    if(a.m_size >= b.m_size) {
        *this = a;
        other = b;
    }
    else if(a.m_size < b.m_size) {                                    //УТЕКАЕТ ЛИ ПАМЯТЬ ПРОВЕРИТЬ
        *this = b;
        other = a;
    }
    int j;
    for(int i = m_size-1, j = other.m_size-1; i >= m_size-other.m_size; --i, --j) {
        m_string[i] += other.m_string[j] - '0' + mind;
        mind = 0;
        if(m_string[i] > '9') {
            m_string[i] -= 10;
            mind = 1;
        }
    }
    if (mind = 1) {
        mind = 0;
        int predydushee = m_size-other.m_size-1;
        if(a.m_size != b.m_size) {
            m_string[predydushee] += 1;
            for (int i = predydushee; i >=1; --i){
                if(m_string[i] > '9') {
                    m_string[i-1] += 1;
                    m_string[i] = '0';
                }
            }
            if(m_string[0] > '9') {
                m_string[0] = '0';
                add1toBegin('1');
            }
        }
        else add1toBegin('1');
    }
}

void intvar::add1toBegin(int whatAdd){
    expandStringBy(1);
    for (int i = m_size; i >= 1; --i) {
        m_string[i] = m_string[i-1];
    }
    m_string[0] = whatAdd;
}

void intvar::combineStrings(intvar& a, intvar& b){
    *this = a;
    expandStringBy(b.m_size);
    int j = 0;
    for (int i = m_size-b.m_size; i<m_size; ++i, ++j)
        m_string[i] = b.m_string[j];
}

void intvar::print() {
    for(int i = 0; i < m_size; ++i){
        std::cout << m_string[i];
    }
    std::cout << std::endl;
}
int intvar::getSize() {
    return m_size;
}

int intvar::searchPoint() {
    char b;
    for (int i = 0; i < m_size; ++i) 
    {
        b = m_string[i];
        if (b == 44 || b == 46)
            return i;
    }
    return m_size;
}

void intvar::expandStringBy(int howMuchExpand){
    m_size+=howMuchExpand;
    char *tempString = new char[m_size];
    for(int i = 0; i <m_size-howMuchExpand; ++i)
        tempString[i] = m_string[i];
    delete[] m_string;
    m_string = tempString;
    std::cout << "string expanded by " << howMuchExpand << std::endl;
}


bool intvar::isDigit(int symbolNumber){
    if (m_string[symbolNumber] >= 48 && m_string[symbolNumber] < 58)
        return 1;
    else
        return 0;
}
bool intvar::isNumber(){
    if (m_string[0] == 44 || m_string[0] == 46 || m_string[m_size-1] == 44 || m_string[m_size-1] == 46)
        return 0;
    int points = 0;
    int spaces = 0;
    int drob = 0;
    int skobkaLeft = 0;
    int skobkaRight = 0;
    for (int i = 0; i < m_size; i++)
    {
        if(!isDigit(i))
        {
            if (m_string[i] == 44 || m_string[i] == 46){
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
            if (m_string[i] == ' '){
                spaces++;
                if(spaces > 1){
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
