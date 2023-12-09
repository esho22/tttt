// FCAI – Object-Oriented Programming – 2023 - Assignment 2
// Program Name: BigDecimalInt
// Author1 and ID and Group: Hesham Hanfy  ID: 20210445
// Author2 and ID and Group: Amr Wael  ID: 20220539 
// Author3 and ID and Group: Tarek Muhamed  ID: 20220170
/*
description: In this problem we developed a new C++ type (class).
that can hold unlimited decimal integer values and performs arithmetic operations on them.
such as: +, -, <, and >.
 */
#pragma once
#ifndef BIGDECIMALINT_BIGDECIMALINTCLASS_H
#define BIGDECIMALINT_BIGDECIMALINTCLASS_H

#include <iostream>
#include <deque>
#include <regex>

using namespace std;
void sameSize(string &num1, string &num2);

class BigDecimalInt{
private:
    string number;
    char signNumber;
    bool checkValidInput(string input);

public:
    bool operator < (const BigDecimalInt& anotherDec);
    bool operator > (const BigDecimalInt& anotherDec);
    bool operator == (const BigDecimalInt anotherDec);
    BigDecimalInt& operator = (BigDecimalInt anotherDec);
    BigDecimalInt operator + (BigDecimalInt number2);
    BigDecimalInt operator - (BigDecimalInt anotherDec);
    friend ostream &operator << (ostream &out, BigDecimalInt num);
    friend istream &operator >> (istream &in, BigDecimalInt& num);

    int size();
    int sign();
    void setNumber(string num);
    string getNumber(){
        return number;
    }

    char getSignNumber();
    void setSign(char s);


    BigDecimalInt(){}
    BigDecimalInt(int decInt);
    BigDecimalInt(string num)
    {
        setNumber(num);
    }

};

#endif //BIGDECIMALINT_BIGDECIMALINTCLASS_H
