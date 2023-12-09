// FCAI – Object-Oriented Programming – 2023 - Assignment 2
// Program Name: BigDecimalInt
// Author1 and ID and Group: Hesham Hanfy   ID: 20210445      S4
// Author2 and ID and Group: Amr Wael       ID: 20220539      S4  
// Author3 and ID and Group: Tarek Muhamed  ID: 20220170      S4 
#include "BigReal.h"
#include "BigReal.cpp"

int main()
{
    BigReal a1("0010.3");
    BigReal a2("10.9");

    cout<<"Test << operator "<<a1<<endl;

    a1 = a2;
    cout<<"Test assignment opreator "<<a1<<endl;

    BigReal a3 = BigReal(BigDecimalInt("444"));
    cout<<"Test bigDecimalInt constructor "<<a3<<endl;

    BigReal a4 = BigReal(100.085445);
    cout<<"Test double constructor "<<a4<<endl;

    BigReal a5 = BigReal(a4);
    cout<<"Test copy constructor "<<a5<<endl;

    BigReal a6(BigReal("3.11"));
    cout<<"Test move constructor "<<a6.getIntgerPart()<<"."<<a6.getDecimalPart()<<endl;

    cout<<"Test > operator "<<(a5>a6)<<endl;

    cout<<"Test < operator "<<(a5<a6)<<endl;
    
    BigReal a7("01.22");
    BigReal a8("-1.22");
    cout<<"Test == operator "<<(a7==a8)<<endl;

    cout<<"Test 1 for - operator "<<(a7-a6)<<endl;

    cout<<"Test 2 for - operator "<<(a6-a8)<<endl;
    
    cout<<"Test 3 for - operator "<<(a7-a4)<<endl;

    cout<<"Test 1 for + operator "<<(a7+a6)<<endl;

    cout<<"Test 2 for + operator "<<(a6+a8)<<endl;
    
    cout<<"Test 3 for + operator "<<(a7+a4)<<endl;


}
