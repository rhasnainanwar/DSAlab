#include "date.h" //our class header
#include <iostream>
#include <sstream>
#include <assert.h>

/* PROTOTYPES */

//free functions
bool is_correct(int m, int d, int y); // make sure that date is valid; using m-d-y
bool is_leap(int year); //checks if given year is a leap year
int days_in_month(int month, int year); // gives days in a given month

static string month_names [] = {"January","February","March","April",
				                "May","June","July","August",
				                "September","October","November","December"};
				 
static string day_names [] = {"Sunday","Monday","Tuesday","Wednesday", // week starts with sunday
                              "Thursday","Friday","Saturday"};

/* Date CLASS IMPLEMENTATION */

// constructor with default values
Date::Date(int initial_month, int initial_day, int initial_year){
    
    assert( is_correct( initial_month, initial_day, initial_year ) );
    
    //set the passed values
    mm   = initial_month;
    dd   = initial_day;
    yyyy = initial_year;
}

/* ACCESSORS */
int Date::month() const //returns month no., 1-12
{
    return mm;
}

int Date::day() const //returns day, 1-7
{
    return dd;
}

int Date::year() const //return year, all four digits
{
    return yyyy;
}

// returns whole date in string format
string Date::string_name() const {
    ostringstream oss;
    oss << month_names[ mm - 1 ] << " " << dd << ", " << yyyy;
    return oss.str();
}
// returns the day of the week
string Date::day_of_week() const {
    
    // as given in description
    int a, b, c, d;
    
    if(mm > 2){ //for march and onward
        a = mm - 2; //month
        c = yyyy%100; // year
    }
    else { //for jan, feb
        a = mm + 10; //month
        c = yyyy%100 - 1; // year
    }
    b = dd; // day
    d = yyyy/100; //century
    
    int w = (13*a - 1) / 5;
    int x = c / 4;
    int y = d /4;
    int z = w + x + y + b + c - 2*d;
    
    return day_names[ z % 7 ];
}

/* COMPARISONS */

// equality
bool operator ==(Date lhs, Date rhs){
    // return true if all three are same, and false otherwise
    return ( (lhs.mm == rhs.mm) && (lhs.dd == rhs.dd)
            && (lhs.yyyy == rhs.yyyy) );
}

// checks if lhs < rhs
bool operator <(Date lhs, Date rhs){
    // return true if lhs is earlier than rhs, and false otherwise
    ostringstream left, right;
    left << lhs.yyyy << "/" << lhs.mm << "/" << lhs.dd;
    right << rhs.yyyy << "/" << rhs.mm << "/" << rhs.dd;
    if( left.str().compare(right.str()) < 0) // if left < right
        return true; //return true
    
    return false; // otherwise, return false
}

// checks if lhs > rhs
bool operator >(Date lhs, Date rhs){
    // return true if lhs is later than rhs, and false otherwise
    return !((lhs == rhs) || (lhs < rhs));
}

// checks if lhs >= rhs
bool operator >=(Date lhs, Date rhs){
    // return true if lhs is later than or same as rhs, and false otherwise
    //return (lhs == rhs) || (lhs > rhs);
    return !( lhs < rhs );
}

// checks if lhs <= rhs
bool operator <=(Date lhs, Date rhs){
    // return true if lhs is earlier than or same as rhs, and false otherwise
    //return (lhs == rhs) || (lhs < rhs);
    return !( lhs > rhs );
}

// inequality
bool operator !=(Date lhs, Date rhs){
    // return true if either one is not same, and false otherwise
    return !(lhs == rhs); // re-using equality
}

/* STREAM IN & OUT */
// set date from in stream
istream& operator >>(istream& in, Date& a_date){
    int m, d, y;
    char sep; //separator
    
    //reading 
    in >> m; //month
    
    in.get(sep);
    if (sep != '/')
      in.setstate(ios::failbit);
      
    in >> d; //day
    
    in.get(sep);
    if (sep != '/')
      in.setstate(ios::failbit);
      
    in >> y; //year
    
    if(in.fail())
        return in;
    
    if(!is_correct(m, d, y)){
        in.setstate(ios_base::failbit);
        return in;
    }
    
    if (in) {
      // All extraction worked, set date
      a_date.mm = m;
      a_date.dd = d;
      a_date.yyyy = y;
    }

    return in;
}

// write to out stream
ostream& operator <<(ostream& out, Date& a_date){
    out << a_date.mm << "/" << a_date.dd << "/" << a_date.yyyy;
    return out;
}

/* FREE FUNCTION DEFINITIONS */

// checks leap year
bool is_leap(int year) {
    // return true if leap year, and false otherwise
    return ( year % 400 == 0 ) || ((year % 4 == 0) 
	&& ( year % 100 != 0 )); 
}

// returns no. of days in given month of given year
int days_in_month(int month, int year) {
    int days = 30; // default

    // 30 days for september, april, june, and november
    // other months have 31 as below (except February)
    
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12){
        days++;
    }
    else if (month == 2){       // for February
        days = 28;
        if (is_leap(year))      // add 1 for leap years, feb 29
            days ++;
    }
    return days;
}


// checks for valid date
bool is_correct(int m, int d, int y){
    if (m < 1 || 12 < m)        // month out of range
        return false;
    
    if (d < 1 || days_in_month(m,y) < d)   // day out of range
        return false;
    
    if (y <= 0) // invalid year
        return false;
        
    // true if no problem found
    return true;
}