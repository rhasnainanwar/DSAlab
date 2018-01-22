#include "polynomial.cpp"

int main(){

    cout << "Welcome to Polynomial Calculator!" << endl;
    cout << "Enter a command from the menu below:" << endl;

    cout << "I - Enter a new current polynomial" << endl;
    cout << "P - Display/print current polynomial" << endl;
    cout << "D - Show the degree of current polynomial" << endl;
    cout << "E - Enter a real number, display the value of polynomial for that number" << endl;
    cout << "A - Enter a new polynomial, add it with current polynomial and show result" << endl;
    cout << "M - Enter a new polynomial, multiply it with current polynomial and show result" << endl;
    cout << "Q - Quit the calculator" << endl;

    char choice;
    vector<int> initial_coefficients;
    vector<int> initial_exponents;
    
    Polynomial poly(initial_coefficients, initial_exponents);
    Polynomial poly2;
    Polynomial res;
    
    bool stop = false;
    while(true){
        cout << endl << "Enter your command: ";
        cin >> choice;
        switch(tolower(choice, loc)){
        case 'i':
            cout << "Enter the polynomial: ";
            cin >> poly;
            break;

        case 'p':
            cout << "The polynomial is: ";
            cout << poly << endl;
            break;

        case 'd':
            cout << "The degree of polynomial is: ";
            cout << poly.degree() << endl;
            break;

        case 'e':
            double x;
            cout << "Enter the value of x: ";
            cin >> x;
            cout << "The value of polynomial is " << poly.evaluate(x) << endl;;
            break;

        case 'a':
            cout << "Enter the new polynomial: ";
            cin >> poly2;
            res = poly + poly2;
            cout << res << endl;;
            break;

        case 'm':
            cout << "Enter the new polynomial: ";
            cin >> poly2;
            res = poly * poly2;
            cout << res << endl;;
            break;

        case 'q':
            cout << "Exited!" << endl;
            stop = true;
            break;

        default:
            cout << "INVALID!" << endl;
        }
        if(stop)
            break;
    }
    return 0;
}
