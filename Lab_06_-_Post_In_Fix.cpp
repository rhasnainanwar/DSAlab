#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <sstream>
#include <assert.h>

using namespace std;

// prototypes
int solveinfix(string);
string in_to_post(string);
int solvepostfix(string);
int solve(int, int, char);
void printexp(string);
bool hasPrecedence(char, char);
bool checkoutput(string);

int main() {

	string input;
	cout << "Enter the expression in in-fix notation to solve: ";
	getline(cin, input);

    assert(checkoutput(input));
    cout << "Assertion Succeeded!!" << endl;

	return 0;
}

bool checkoutput(string input){
    printexp(input); // print in standard format

	int in = solveinfix(input);

	string inpost = in_to_post(input);

    printexp(inpost); // print in post fix notation

	int post = solvepostfix(inpost);
	return in == post;
}
// gets expression as comma separated string
// outputs the evaluation result
int solveinfix(string input){
	stack<int> operands;
	stack<char> operators;

	vector<string> tokens; // split expression over comma
	stringstream ss(input); // make it a string stream for parsing
	string temp;

	while (getline(ss, temp, ','))
		tokens.push_back(temp); // keep pushing each token

	for (auto& value : tokens){
		stringstream test(value);
		int number;
		char op;
		if (test >> number)// if token is a number
			operands.push(number); // push it

		else{
			// go back
			test.clear();
			test.seekg(0, test.beg);

			test >> op; // get operator

			// current token is an opening brace, add it to operators
			if (op == '(')
				operators.push(op);

			// closing brace encountered, solve entire brace
			else if (op == ')')
			{
				while (operators.top() != '('){
					// get values
					// note that the pop() works backwards
					int second = operands.top();
					operands.pop();
					int first = operands.top();
					operands.pop();
					char oper = operators.top();
					operators.pop();
					// first oper second; important for subtraction and division
					operands.push(solve(first, second, oper)); // solve and push the answer again for further evaluation
				}
				operators.pop(); // remove the opening brace
			}

			// if artihmetic operator
			else if (op == '+' || op == '-' ||
				op == 'x' || op == '/')
			{
				while (!operators.empty() && hasPrecedence(op, operators.top())){
					// get values
					// note that the pop() works backwards
					int second = operands.top();
					operands.pop();
					int first = operands.top();
					operands.pop();
					char oper = operators.top();
					operators.pop();
					// first oper second; important for subtraction and division
					operands.push(solve(first, second, oper)); // solve and push the answer again for further evaluation
				}

				// Push current token to operators
				operators.push(op);
			}
		}
	}

	// remaining operations to remaining values
	while (!operators.empty()){
		// get values
		// note that the pop() works backwards
        int second = operands.top();
        operands.pop();
        int first = operands.top();
        operands.pop();
        char oper = operators.top();
        operators.pop();
        // first oper second; important for subtraction and division
        operands.push(solve(first, second, oper)); // solve and push the answer again for further evaluation
	}

	// opernds now contains result, return it
	return operands.top();
}

// gets comma separated expression in infix notation
// outputs comma separated expression in postfix notation
string in_to_post(string input){
    stringstream output("");
	stack<char> operators;
    vector<string> tokens; // split expression over comma
	stringstream ss(input); // make it a string stream for parsing
	string temp;
	while (getline(ss, temp, ',')) {
		tokens.push_back(temp); // keep pushing each token
	}

	for (auto& value : tokens){
		stringstream test(value);
		int number;
		char op;
		if (test >> number){ // if token is a number
			output << number; // push it
			output << ",";
		}
		else{
			// go back
			test.clear();
			test.seekg(0, test.beg);
			test >> op; // get operator

			if (op == '(')
				operators.push(op);

			// closing brace encountered, solve entire brace
			else if (op == ')')
			{
				while (operators.top() != '('){
					char temp = operators.top();
					operators.pop();
                    output << temp;
                    output << ",";
				}
				operators.pop(); // remove the opening brace
			}

			// if arithmetic operator
			else if (op == '+' || op == '-' ||
				op == 'x' || op == '/')
			{
				while (!operators.empty() && hasPrecedence(op, operators.top())){
                    char temp = operators.top();
					operators.pop();
                    output << temp;
                    output << ",";
				}

				// Push current token to operators
				operators.push(op);
			}
		}
	}

	while (!operators.empty()){
		// get values
		char temp = operators.top();
        operators.pop();
        output << temp;
        output << ",";
	}

	string out;
	output >> out;
	return out.substr(0, out.length() - 1);
}

// gets expression as comma separated string
// outputs the evaluation result
int solvepostfix(string input){
	stack<int> numbers; // a stack to hold numbers
	vector<string> tokens; // split expression over comma
	stringstream ss(input); // make it a string stream for parsing
	string temp;
	while (getline(ss, temp, ',')) {
		tokens.push_back(temp); // keep pushing each token
	}

	for (auto& value : tokens){
		stringstream test(value);
		int number;
		char op;
		if (test >> number) // if token is a number
			numbers.push(number); // push it
		else{
			// go back
			test.clear();
			test.seekg(0, test.beg);
			test >> op; // get operator

			// get values
            // note that the pop() works backwards
            int second = numbers.top();
            numbers.pop();
            int first = numbers.top();
            numbers.pop();
            // first oper second; important for subtraction and division
            numbers.push(solve(first, second, op)); // solve and push the answer again for further evaluation
		}
	}

	return numbers.top();
}

// performs arithmetic operations on given numbers
int solve(int x, int y, char op){
	switch (op)
	{
	case '+':
		return x + y;
		break;
	case '-':
		return x - y;
		break;
	case 'x':
		return x * y;
		break;
	case '/':
		return x / y;
		break;
	default:
		break;
	}
	return 0;
}

// prints coma separated expression in mathematical form
void printexp(string ex){
	replace(ex.begin(), ex.end(), ',', ' ');
	cout << endl << "Solving: " << ex << endl;
}

// checks if an operator has precedence over another
bool hasPrecedence(char op1, char op2){
	if (op2 == '(' || op2 == ')')
		return false;
	if ((op1 == 'x' || op1 == '/') && (op2 == '+' || op2 == '-'))
		return false;
	return true;
}
