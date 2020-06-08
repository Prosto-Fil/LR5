#pragma once
#include <iostream>

class NewInt
{
private:
    int data;
public:
    NewInt() {}
    NewInt(int per)
    {
        this->data = per;
    }
    friend std::ostream& operator << (std::ostream& out, NewInt& testint)
    {
        out << testint.data;
        return out;
    }
};