/*
* Kindly fill this information.
* Name:
* Student #:
*/

#include <iostream>
#include <string>

using namespace std;

/*
* Define a struct Area that has two private variable members;
* units of type string and area_value of type float.
*/
class Area
{
	private:
		string units;
		float area_value;

public:
	void set_units(string u){
		units = u;
	}
	void set_area(float area){
		area_value = area;
	}
	string get_units(){
		return units;
	}

	float get_area(){
		return area_value;
	}
};

int main()
{
	/*
	* Modify program to create a dynamic variable of type Area.
	*/

	Area *area1 =  new Area;


	/*
	* Input from the keyboard the area_value and its units.
	*/
	float area_value;
	cout << "Enter area value: ";
	cin >> area_value;
	(*area1).set_area(area_value);

	string units;
	cout << "Enter Units: ";
	cin >> units;
	(*area1).set_units(units);


	/*
	* Compute one-half and one-quarter of the area
	* and display the results
	*/

	cout << (*area1).get_area() / 2.0 << " " << (*area1).get_units() << endl;

	cout << (*area1).get_area() / 4.0 << " " << (*area1).get_units() << endl;

	/*
	* Destroy the dynamic variable at the end
	*/

	delete area1;


	return 0;
}