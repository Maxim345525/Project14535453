#include <iostream>
#include <cstring>
using namespace std;
class String {
protected:
    char* str;
    int length;
public:
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    int getLength() const {
        return length;
    }
    void clear() {
        delete[] str;
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }
    virtual ~String() {
        delete[] str;
    }
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        delete[] result.str;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }
    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }
    bool operator!=(const String& other) const {
        return !(*this == other);
    }
};
class BitString : public String {
public:
    BitString() : String() {}
    BitString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        bool valid = true;
        for (int i = 0; i < length; ++i) {
            if (s[i] != '0' && s[i] != '1') {
                valid = false;
                break;
            }
        }
        if (valid)
            strcpy(str, s);
        else {
            str[0] = '\0';
            length = 0;
        }
    }
    BitString(const BitString& other) : String(other) {}
    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }
    void changeSign() {
        for (int i = 0; i < length; ++i) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
    }
    BitString operator+(const BitString& other) const {
        BitString result;
        String::operator+(other);
        return result;
    }
    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }
    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }
};
template<typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;
public:
    Base() {}
    Base(T1 val1, T2 val2) : value1(val1), value2(val2) {}
    virtual ~Base() {}
};
template<typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;
public:
    Child() {}
    Child(T1 val1, T2 val2, T3 val3, T4 val4) : Base<T1, T2>(val1, val2), value3(val3), value4(val4) {}
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;
    T5 value5;
    T6 value6;
public:
    Child2() {}
    Child2(T1 val1, T2 val2, T3 val3, T4 val4, T5 val5, T6 val6) : Base<T1, T2>(val1, val2), value3(val3), value4(val4), value5(val5), value6(val6) {}
};

int main() {
    String str1("Hello");
    String str2 = "World";
    String str3 = str1 + str2;
    cout << "str1: " << str1.getLength() << " " << str1 << endl;
    cout << "str2: " << str2.getLength() << " " << str2 << endl;
    cout << "str3: " << str3.getLength() << " " << str3 << endl;
    BitString bitStr1("1010");
    BitString bitStr2("1100");
    BitString bitStr3 = bitStr1 + bitStr2;
    cout << "bitStr1: " << bitStr1.getLength() << " " << bitStr1 << endl;
    cout << "bitStr2: " << bitStr2.getLength() << " " << bitStr2 << endl;
    cout << "bitStr3: " << bitStr3.getLength() << " " << bitStr3 << endl;
    Child<int, double, char, string> child1(10, 3.14, 'a', "hello");
    Child2<int, double, char, string, bool, float> child2(20, 6.28, 'b', "world", true, 2.5);
    return 0;
}