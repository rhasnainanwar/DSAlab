#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <sstream>

using namespace std;

int solveinfix(string input);
int solvepostfix(string input);
int solve(int x, int y, char op);
void printexp(string);
bool hasPrecedence(char op1, char op2);

int main() {

	string input;
	cout << "Enter the expression in in-fix notation to solve: ";
	getline(cin, input);

	printexp(input);

	int in = solveinfix(input);

	int post = solvepostfix(input);
	cout << "Post fix answer: " << post << endl;
	return 0;
}

int solveinfix(string input){
	stack<int> operands;
	stack<char> operators;

	vector<string> tokens; // split expression over comma
	stringstream ss(input); // make it a string stream for parsing
	string temp;

	while (getline(ss, temp, ',')) {
		tokens.push_back(temp); // keep pushing each token
		cout << temp << endl;
	}

	for (auto& value : tokens){
		stringstream test(value);
		int number;
		char op;
		if (test >> number) // if token is a number
			operands.push(number); // push it
		else{
			// go back
			test.clear();
			test.seekg(0, test.beg);

			test >> op; // get opeartor
			
			// current token is an opening brace, add it to operators
			if (op == '(')
				operators.push(op);

			// closing brace encountered, solve entire brace
			else if (op == ')')
			{
				while (operators.top() != '('){
					// get values
					int first = operands.top();
					operands.pop();
					int second = operands.top();
					operands.pop();
					char oper = operators.top();
					operators.pop();
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
					int first = operands.top();
					operands.pop();
					int second = operands.top();
					operands.pop();
					char oper = operators.top();
					operators.pop();
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
		int first = operands.top();
		operands.pop();
		int second = operands.top();
		operands.pop();
		char oper = operators.top();
		operators.pop();
		operands.push(solve(first, second, oper)); // solve and push the answer again for further evaluation
	}

	// opernds now contains result, return it
	return operands.top();
}

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
			test >> op; // get opeartor
			// get two recently added values
			int first = numbers.top();
			numbers.pop();
			int second = numbers.top();
			numbers.pop();
			numbers.push(solve(first, second, op)); // solve and push the answer again for further evaluation
		}
	}

	return numbers.top();
}

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

void printexp(string ex){
	replace(ex.begin(), ex.end(), ',', ' ');
	cout << endl << "Solving: " << ex << endl;
}

bool hasPrecedence(char op1, char op2){
	if (op2 == '(' || op2 == ')')
		return false;
	if ((op1 == 'x' || op1 == '/') && (op2 == '+' || op2 == '-'))
		return false;
	return true;
}