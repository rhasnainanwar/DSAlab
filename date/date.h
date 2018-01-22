#ifndef _DATE_H
#define _DATE_H

// Date(int m,int d,int y) ---  constructor requires three parameters:
//                              month, day, year; with default date 
//                              1, 1, 2017

// int Month()             --- return, respectively, month, day, and year
// int Day()
// int Year()

// string string_name()    --- return date in written format e.g., January 1, 2017

// string day_of_week()    --- return the day of week from date

// date comparisons using overloaded operators
//  friend bool operator ==(Date, Date)     --- return bool according to the comparison
//    friend bool operator <(Date, Date)    --- //
//    friend bool operator >(Date, Date)    --- //
//    friend bool operator <=(Date, Date)   --- //
//    friend bool operator >=(Date, Date)   --- //
//    friend bool operator !=(Date, Date)   --- //

// like cin, cout
// friend bool operator >>(istream&, Date&)
// friend bool operator <<(ostream&, Date&)

#include <string>
using namespace std;

class Date {
    //attributes
    private:
        int mm;               // month of the year, 1-12
        int dd;                // day of the month, variations according to the current month
        int yyyy;              // year in four digits, must be greater than 0
        
        
    public:
        // Constructor & Destructor
        Date(int initial_month = 1, int initial_day = 1, int initial_year = 2017);
        
        /* --- OPERATIONS & FUNCTIONS --- */
        
        /* attribute getters */
        int month() const;
        int day()   const;
        int year()  const;
        
        /* operations and data representation */
        
        // returns the date as 'Month_name day, year'; equivalent to toString()
        string string_name() const;
        // returns the day of week
        string day_of_week() const;
        
        /* overloaded operators */
        
        // comparison of two dates using overloaded operators
        friend bool operator ==(Date, Date);
        friend bool operator <(Date, Date);
        friend bool operator >(Date, Date);
        friend bool operator <=(Date, Date);
        friend bool operator >=(Date, Date);
        friend bool operator !=(Date, Date);
        //read from stream
        friend istream& operator >>(istream&, Date&);
        // write to stream
        friend ostream& operator <<(ostream&, Date&);
};

#endif