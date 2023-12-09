#include "BigReal.h"

BigReal::BigReal() : integerPart("0"), decimalPart("0") {}

// Default constructor
BigReal::BigReal(double realNumber)
{
    string realNumberStr = to_string(realNumber);
    int decimalPointIndex = realNumberStr.find('.');
    string integerPartStr = realNumberStr.substr(0, decimalPointIndex);
    string decimalPartStr = realNumberStr.substr(decimalPointIndex + 1);
    integerPart = BigDecimalInt(integerPartStr);
    decimalPart = BigDecimalInt(decimalPartStr);
}

BigReal::BigReal(string realNumber)
{
    int decimalPointIndex = realNumber.find('.');
    if (decimalPointIndex == -1)
    {
        integerPart = BigDecimalInt(realNumber);
        decimalPart = BigDecimalInt("0");
    }
    else
    {
        string integerPartStr = realNumber.substr(0, decimalPointIndex);
        string decimalPartStr = realNumber.substr(decimalPointIndex + 1);
        integerPart = BigDecimalInt(integerPartStr);
        decimalPart = BigDecimalInt(decimalPartStr);
    }
}

BigReal::BigReal(BigDecimalInt bigInteger)
{
    integerPart = bigInteger;
    decimalPart = BigDecimalInt(0);
}

// Copy constructor
BigReal::BigReal(const BigReal &other)
{
    integerPart = other.integerPart;
    decimalPart = other.decimalPart;
}

// Move constructor
BigReal::BigReal(BigReal &&other)
{
    integerPart = other.integerPart;
    decimalPart = other.decimalPart;
    other.integerPart = BigDecimalInt(0);
    other.decimalPart = BigDecimalInt(0);
}

// Assignment operator
BigReal &BigReal::operator=(BigReal &other)
{
    integerPart = other.integerPart;
    decimalPart = other.decimalPart;
    return *this;
}

BigReal &BigReal::operator=(BigReal &&other)
{
    integerPart = other.integerPart;
    decimalPart = other.decimalPart;
    return *this;
}

BigDecimalInt BigReal::getIntgerPart() { return integerPart; }
BigDecimalInt BigReal::getDecimalPart() { return decimalPart; }

void setZeros(BigDecimalInt &f, BigDecimalInt &s)
{
    string str1 = f.getNumber();
    string str2 = s.getNumber();
    int diff = abs(f.size() - s.size());

    if (str1.size() > str2.size())
    {
        for (int i = 0; i < diff; i++)
        {
            str2 += "0";
        }
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            str1 += "0";
        }
    }
    f.setNumber(str1);
    s.setNumber(str2);
}

bool BigReal::operator<(BigReal anotherReal)
{
    int s1, s2;
    s1 = integerPart.sign();
    s1 = integerPart.sign();

    if (integerPart < anotherReal.integerPart)
    {
        return true;
    }
    if (decimalPart.size() != anotherReal.decimalPart.size())
    {
        setZeros(decimalPart, anotherReal.decimalPart);
    }

    if (integerPart == anotherReal.integerPart)
    {
        if (decimalPart < anotherReal.decimalPart && s1 == 1)
        {
            return true;
        }
        if (decimalPart < anotherReal.decimalPart && s1 == 0)
        {
            return false;
        }
        if (decimalPart > anotherReal.decimalPart && s1 == 1)
        {
            return false;
        }
        if (decimalPart > anotherReal.decimalPart && s1 == 0)
        {
            return true;
        }
    }
    return false;
}

bool BigReal::operator>(BigReal anotherReal)
{
    int s1, s2;
    s1 = integerPart.sign();
    s1 = integerPart.sign();

    if (integerPart > anotherReal.integerPart)
    {
        return true;
    }
    if (decimalPart.size() != anotherReal.decimalPart.size())
    {
        setZeros(decimalPart, anotherReal.decimalPart);
    }

    if (integerPart == anotherReal.integerPart)
    {
        if (decimalPart > anotherReal.decimalPart && s1 == 1)
        {
            return true;
        }
        if (decimalPart > anotherReal.decimalPart && s1 == 0)
        {
            return false;
        }
        if (decimalPart < anotherReal.decimalPart && s1 == 1)
        {
            return false;
        }
        if (decimalPart < anotherReal.decimalPart && s1 == 0)
        {
            return true;
        }
    }
    return false;
}

bool BigReal::operator==(BigReal anotherReal)
{
    if (integerPart == anotherReal.integerPart and decimalPart == anotherReal.decimalPart)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BigReal::size()
{
    int total;
    total = integerPart.size() + decimalPart.size();
    return total;
}
int BigReal::sign()
{
    return integerPart.sign();
}

ostream &operator<<(ostream &out, BigReal num)
{
    out << num.integerPart << "." << num.decimalPart;
    return out;
}
istream &operator>>(istream &in, BigReal &num)
{
    string n;
    in >> n;
    BigReal real(n);
    num = real;
    return in;
}

BigReal BigReal::operator+(BigReal &other)
{
    BigReal sum;
    BigDecimalInt num("1");
    sum.integerPart = integerPart + other.integerPart;
    if (decimalPart.size() > other.decimalPart.size())
    {
        while (decimalPart.size() > other.decimalPart.size())
        {
            other.decimalPart.setNumber(other.decimalPart.getNumber() + '0');
        }
    }
    if (decimalPart.size() < other.decimalPart.size())
    {
        while (decimalPart.size() < other.decimalPart.size())
        {
            decimalPart.setNumber(decimalPart.getNumber() + '0');
        }
    }

    if (integerPart.getSignNumber() == '+' && other.integerPart.getSignNumber() == '+')
    {

        sum.decimalPart = decimalPart + other.decimalPart;

        if (sum.decimalPart.size() > decimalPart.size())
        {
            sum.decimalPart.setNumber(sum.decimalPart.getNumber().substr(1));
            sum.integerPart = sum.integerPart + num;
        }
    }
    else if (integerPart.getSignNumber() == '+' && other.integerPart.getSignNumber() == '-')
    {
        other.integerPart.setSign('+');
       
        if (integerPart > other.integerPart)
        {
            if (decimalPart < other.decimalPart)
            {
                BigDecimalInt n("1" + decimalPart.getNumber());
                sum.decimalPart = n - other.decimalPart;
                sum.integerPart = sum.integerPart - num;
            }
            else if (decimalPart > other.decimalPart)
            {
                sum.decimalPart = decimalPart - other.decimalPart;
            }
        }
        else if (integerPart < other.integerPart)
        {
            if (decimalPart > other.decimalPart)
            {
                BigDecimalInt n("1" + other.decimalPart.getNumber());
                sum.decimalPart = n - decimalPart;
                sum.integerPart = sum.integerPart + num;
            }
            else if (decimalPart < other.decimalPart)
            {
                sum.decimalPart = other.decimalPart - decimalPart;
            }
            sum.integerPart.setSign('-');
        }
        else if (integerPart == other.integerPart)
        {
            if (decimalPart > other.decimalPart)
            {
                sum.decimalPart = decimalPart - other.decimalPart;
            }
            else if (decimalPart < other.decimalPart)
            {
                sum.decimalPart = other.decimalPart - decimalPart;
                sum.integerPart.setSign('-');
            }
        }

        other.integerPart.setSign('-');
       
    }
    else if (integerPart.getSignNumber() == '-' && other.integerPart.getSignNumber() == '+')
    {
        this->integerPart.setSign('+');
        other.integerPart.setSign('-');

        BigReal res = *this + other;
        if (res.integerPart.getSignNumber() == '+')
        {
            res.integerPart.setSign('-');
        }
        else
        {
            res.integerPart.setSign('+');
        }
        if (res.integerPart.getNumber() == "0" && res.decimalPart.getNumber() == "0")
        {
            res.integerPart.setSign('+');
        }

        this->integerPart.setSign('+');
        other.integerPart.setSign('-');
        sum = res;
    }
    if (integerPart.getSignNumber() == '-' && other.integerPart.getSignNumber() == '-')
    {

        sum.decimalPart = decimalPart + other.decimalPart;
        if (sum.decimalPart.size() > decimalPart.size())
        {
            sum.decimalPart.setNumber(sum.decimalPart.getNumber().substr(1));
            sum.integerPart = sum.integerPart - num;
        }
    }
    return sum;
}

BigReal BigReal::operator-(BigReal &other)
{
    BigReal sum;
    BigDecimalInt num("1");
    sum.integerPart = integerPart - other.integerPart;
    if (decimalPart.size() > other.decimalPart.size())
    {
        while (decimalPart.size() > other.decimalPart.size())
        {
            other.decimalPart.setNumber(other.decimalPart.getNumber() + '0');
        }
    }
    if (decimalPart.size() < other.decimalPart.size())
    {
        while (decimalPart.size() < other.decimalPart.size())
        {
            decimalPart.setNumber(decimalPart.getNumber() + '0');
        }
    }

    if (integerPart.getSignNumber() == '+' && other.integerPart.getSignNumber() == '+')
    {
        //+ + -

        other.integerPart.setSign('-');
        sum = *this + other;
        other.integerPart.setSign('+');
    }
    else if (integerPart.getSignNumber() == '-' && other.integerPart.getSignNumber() == '+')
    {

        sum.decimalPart = decimalPart + other.decimalPart;
        if (sum.decimalPart.size() > decimalPart.size())
        {

            sum.decimalPart.setNumber(sum.decimalPart.getNumber().substr(1));
            sum.integerPart = sum.integerPart - num;
            sum.decimalPart.setSign('+');
        }
    }
    else if (integerPart.getSignNumber() == '+' && other.integerPart.getSignNumber() == '-')
    {

        sum.decimalPart = decimalPart + other.decimalPart;
        if (sum.decimalPart.size() > decimalPart.size())
        {

            sum.decimalPart.setNumber(sum.decimalPart.getNumber().substr(1));
            sum.integerPart = sum.integerPart + num;
            sum.decimalPart.setSign('+');
        }
    }
    else if (integerPart.getSignNumber() == '-' && other.integerPart.getSignNumber() == '-')
    {
        // - + +
        other.integerPart.setSign('+');
        sum = *this + other;
        other.integerPart.setSign('-');
    }
    return sum;
}
