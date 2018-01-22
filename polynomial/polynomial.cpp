#include "polynomial.h"
#include <math.h>

/*  CONSTRUCTORS  */
// default constructor
Polynomial::Polynomial() {
    coefficients.push_back(0);
}

// explicit value constructor which creates a polynomial using given coefficients and exponents
Polynomial::Polynomial(vector<int> initial_coefficients, vector<int> initial_exponents){
    if(initial_coefficients.empty() || initial_exponents.empty())
        coefficients.push_back(0); // a constant polynomial 0
    else {
        // make room for coefficients
        coefficients.resize( initial_exponents[0] + 1);
        
        for(int i = 0; i < initial_exponents.size(); ++i){
            coefficients[ initial_exponents[i] ] = initial_coefficients[i];
        }
        
        while(coefficients[ degree() ] == 0) // if highest power is 0
            coefficients.pop_back(); //drop it!
    }
}

/* Functionality */
//returns the highest exponent in the polynomial
int Polynomial::degree() const{
    return coefficients.size() - 1; // assuming that the last element is non-zero
}

// input: point of evaluation
// output: result of evaluation
// evaluates the polynomial for a particular value of x
double Polynomial::evaluate(double x) const{

    if(!x) // when x is zero
        return coefficients[0]; // only constant is returned to save processing

    double result = 0.0; // evaluation result

    for(int i = 0; i < coefficients.size(); ++i){
        if(!coefficients[i]) // skip the zero terms
            continue;
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

/* overloaded operators */
// adds two passed polynomials and returns the resultant polynomial
Polynomial operator +(Polynomial lhs_poly, Polynomial rhs_poly){
    /* equate polynomials by extending degree using zeros */
    // if left is less than right
    if( lhs_poly.coefficients.size() < rhs_poly.coefficients.size()){
        lhs_poly.coefficients.resize ( rhs_poly.coefficients.size() );
    }
    // if right is less than left
    else if( rhs_poly.coefficients.size() < lhs_poly.coefficients.size()){
        rhs_poly.coefficients.resize ( lhs_poly.coefficients.size() );
    }

    Polynomial sum_poly; // resultant polynomial of addition
    sum_poly.coefficients.pop_back(); //clear default
    
    for(int i = 0; i < rhs_poly.coefficients.size(); ++i) //size of both polynomials is now equal
        sum_poly.coefficients.push_back( lhs_poly.coefficients[i] + rhs_poly.coefficients[i]); // adding

    while(sum_poly.coefficients[ sum_poly.degree() ] == 0) // if highest power is canceled out
        sum_poly.coefficients.pop_back(); //drop it!
    
    return sum_poly; // return new polynomial
}

// multiplies two passed polynomials and returns the resultant polynomial
Polynomial operator *(Polynomial lhs_poly, Polynomial rhs_poly){
    Polynomial sum_poly; // resultant polynomial of multiplication
    
    // degrees of polynomials
    int l_degree = lhs_poly.degree();
    int r_degree = rhs_poly.degree();
    // the highest exponent in product = sum of highest exponents of the multiplied polynomials
    sum_poly.coefficients.resize( l_degree + r_degree + 1);

    // product
    for(int i = 0; i <= l_degree; i++)
        for(int j = 0; j <= r_degree; j++)
            sum_poly.coefficients[i+j] += lhs_poly.coefficients[i] * rhs_poly.coefficients[j]; // multiply coefficients and make exponent i+j

    return sum_poly; // return product
}

/* STREAM IN & OUT */
// make new polynomial from in stream
istream& operator >>(istream& in_stream, Polynomial& a_poly){
    vector<int> initial_coefficients;
    vector<int> initial_exponents;
    int ex, coeff;
    char c;
    
    //ignore white spaces
    do {
        in_stream.get(c);
    } while(c == ' ' || c == '\n' || c == '\t' || c == EOF);
    
    in_stream.putback(c);
    // now we are at the polynomial, and first character is already in c
    while(c != ' ' && c != '\n' && c != '\t' && c != EOF){
        c = in_stream.peek();
        if(c == '+') {
            in_stream.ignore();
            in_stream >> coeff;
            if(in_stream.fail())
                coeff = 1;
        }
        else if(c == '-') {
            in_stream.ignore();
            in_stream >> coeff;
            
            if(in_stream.fail())
                coeff = 1;
                
            coeff = -coeff;
        }
        else {
            in_stream >> coeff;
        }
        
        c = in_stream.peek();
        
        if(c == 'x') {
            in_stream >> c;
            c = in_stream.peek();
            
            if(c == '^') {
                in_stream.ignore();
                in_stream >> ex;
            } else 
                ex = 1;
        } else 
            ex = 0;
        
        // add coefficient and exponent
        initial_coefficients.push_back(coeff);
        initial_exponents.push_back(ex);
    }
    a_poly = Polynomial(initial_coefficients, initial_exponents);
    return in_stream;
}

// write to out stream
ostream& operator <<(ostream& out_stream, Polynomial& a_poly){
    // constant
    if(a_poly.coefficients.size() == 1 && !a_poly.coefficients[0]){
        out_stream << 0;
        return out_stream;
    }
    
    // if we don't want to show an extra '+' at the start of polynomial
    
    for (int i = a_poly.degree(); i > 0; i--)
    {
        if(a_poly.coefficients[i] == 0) // don't show empty terms
            continue;

        if(a_poly.coefficients[i] > 0 && i!=a_poly.degree())  //need to add extra '+' for position coefficients
            out_stream << "+";

        if(a_poly.coefficients[i] != 1) // don't show coefficient if it's 1
            out_stream << a_poly.coefficients[i];

        out_stream << "x"; // write to stream

        if(i != 1)
            out_stream << "^" << i; // write to stream

    }
    if(a_poly.coefficients[0] > 0) //need to add extra '+' for position coefficients
            out_stream << "+";
    out_stream << a_poly.coefficients[0]; // add last constant

    return out_stream;
}