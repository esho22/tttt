#pragma once
#ifndef BIGREAL_H
#define BiGREAL_H

#include "BigDecimalIntClass.h"
#include "BigDecimalIntClass.cpp"

void setZeros(BigDecimalInt& f, BigDecimalInt& s);

class BigReal
{
private:
    BigDecimalInt integerPart;
    BigDecimalInt decimalPart;


public:
    BigReal();
    BigReal(double realNumber  ); // Default constructor
    BigReal(string realNumber);
    BigReal(BigDecimalInt bigInteger);
    BigReal(const BigReal &other);       // Copy constructor
    BigReal(BigReal &&other);            // Move constructor
    BigReal &operator=(BigReal &other);  // Assignment operator
    BigReal &operator=(BigReal &&other); // Move assignment

    //setter & getter
    BigDecimalInt getIntgerPart();
    BigDecimalInt getDecimalPart();

    // Overloading operators
    bool operator<  (BigReal anotherReal);
    bool operator>  (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    BigReal operator+(BigReal& other);
    BigReal operator-(BigReal& other);

    int size();
    int sign();

    friend ostream& operator << (ostream& out, BigReal num); 
    friend istream& operator >> (istream& in, BigReal& num);

};

#endif
