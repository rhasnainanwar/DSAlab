#include "date.cpp"
#include <iostream>

// let's test our Date class
int main(){
    
    Date today(9, 19); //using default values
    
    Date dob(6, 10, 1995); // using full constructor
    //compare both
    
    cout << (today == dob) << endl;
    cout << (today != dob) << endl;
    cout << (today >= dob) << endl;
    cout << (today <= dob) << endl;
    cout << (today > dob) << endl;
    cout << (today < dob) << endl;
    return 0;
}