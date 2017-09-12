/*
* Kindly fill this information.
* Name: Raja Hasnain Anwar
* Student #: 192135

*/

#include <iostream>

using namespace std;

/*
* PROBLEM #2: Analyze pointers
*/

/*
* PART #1: Write a function that does two things:
* >> Write the memory location pointed by the pointer to the console.
* >> Write the value of the integer (which the pointer points to) to the console.
*/
void analyze_pointer(int *ptr)
{
	cout << "Pointer: " << ptr << endl;
	cout << "Value: " << *ptr << endl;

}


/*
* PROBLEM #3: Add a couple more functions to the mix
* >> call them int_pointer1 and int_pointer2
* >> both will return int pointers.
*/

/*
* Follow the steps:
* >> the function will allocate an int on the heap (via new int)
* >> assign a value to it
* >> and return that value (an int pointer type).
*/
int* int_pointer1()
{
	int *ptr = new int;
	*ptr = 425;
	return ptr;

}

/*
* Follow the steps:
* >> the function will allocate an int on the stack (via "int iValue;" or something similar)
* >> assign a value to it
* >> and return its memory location (an int pointer type).
*/
int* int_pointer2()
{
	int something = 435;
	return &something;

}


int main()
{
	/*
	* PART #2: Use the analyze_pointer function to complete two TASKS
	*/

	/*
	* TASK #1
	* >> allocate an int on the stack (e.g.,  "int iValue;")
	* >> assign a value to it
	* >> get its memory location (with the reference operator---&)
	* >> and pass this value to analyze_pointer.
	*/

	cout << "Part #2: Memory on stack..." << endl;

	// Add your code here!
	int iValue; //declared
	iValue = 12; //assign
	int *ptr = &iValue; //memory location
	analyze_pointer(ptr); //pass

	/*
	* TASK #2
	* >> allocate an int on the heap (with the new operator)
	* >> assign a value to it
	* >> and pass it to analyze_pointer.
	*/
	cout << "Memory on heap..." << endl;

	// Add your code here!
	int *new_int; //for heap
	new_int = new int; //in heap
	*new_int = 65; //assign
	analyze_pointer(new_int); //pass
	delete new_int; //clear mem
	/*
	* PROBLEM #3: Call analyze_pointer on the return of functions int_pointer1() and int_pointer2()
	*/
	cout << "Memory on heap versus on stack..." << endl;

	int *temp = int_pointer1();
	analyze_pointer(temp);
	analyze_pointer(int_pointer2());

	/*
	* Remember that int was allocated on the heap for function "int_pointer1()"
	* Delete it
	* and call analyze_pointer on it after deleting it.
	*/
	cout << "Memory on heap after delete..." << endl;

	delete temp;
	analyze_pointer(temp);


	/*
	* Call: analyze_pointer(new int);
	*/

	// Add your code here!
	analyze_pointer(new int);


	return 0;
}
