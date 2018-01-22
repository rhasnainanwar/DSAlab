#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include <iostream>
#include <locale>
#include <vector>
#include <sstream>
using namespace std;

locale loc;

class Polynomial {

    private:
    // a vector to keep coefficients of the polynomial
    vector<int> coefficients;

    public:
        /*  CONSTRUCTORS  */
        // default constructor
        Polynomial();
        // explicit value constructor
        Polynomial(vector<int> initial_coefficients, vector<int> initial_exponents);

        /* Functionality */
        //returns the highest exponent in the polynomial
        int degree() const;

        // input: point of evaluation
        // output: result of evaluation
        // evaluates the polynomial for a particular value of x
        double evaluate(double x) const;

        /* overloaded operators */
        // adds two passed polynomials and returns the resultant polynomial
        friend Polynomial operator +(Polynomial, Polynomial);
        // multiplies two passed polynomials and returns the resultant polynomial
        friend Polynomial operator *(Polynomial, Polynomial);

        //read polynomial from stream
        friend istream& operator >>(istream&, Polynomial&);
        // write polynomial to stream
        friend ostream& operator <<(ostream&, Polynomial&);
};
#endif // _POLYNOMIAL_H
