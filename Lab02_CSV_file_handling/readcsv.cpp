#include "csvrow.cpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
/* READS A CSV FILE AND MANIPULATES WITH DATA*/

// start reading file line-by-line
int main(int argc, char* argv[]){
	//argument check
	if (argc != 2){
		cout << "Usage: " << argv[0] << " <some_csv_file>" << endl;
		exit(1);
	}
	
	ifstream csv(argv[1]);
	// file issues
	if(!csv){
		cout << "Error while reading file. Check your persmissions and try again" << endl;
		exit(1);
	}
	
	// a 2-D vector to hold records in matrix-like order
	vector< vector<string> > data;
	
	// task A
	while(!csv.eof()){ //unless the file ends
		CSVRow row; //create a row object
		row.readNextLine(csv); //read a row from file and create vector
		data.push_back(row.getData()); //get cell vector and push it
	}

	// task B
	cout << "ZERO PASSED IN 10TH:	" << endl;
	for(int i = 0; i < data.size(); ++i)
		if( !data[i][8].compare("0") )
			cout << data[i][1] << endl;
		
	//task C
	cout << endl << "PERCENTAGE LARGE SCHOOLS:	" << endl;
	
	vector<int> largeschools; //vector for large school indices
	int x; //temp
	
	for(int i = 0; i < data.size(); ++i){
		stringstream large(data[i][6]); //get the no. of registrations
		large >> x; //string to int
		
		if( x > 50 ) //check large
			largeschools.push_back(i);
	}
	//percentage
	cout << largeschools.size() * 100.0 / (data.size() - 1) << "%" << endl;
	
	//task D
	cout << endl << "HIGHEST DROPOUT:	" << endl;
	float max = 0.0; //for maximum
	int highest; //highest dropout index
	float check; //current index
	for(int i = 0; i < largeschools.size(); ++i){
		stringstream large(data[ largeschools[i] ][12]); //get the dropout
		large >> check; //string to int
		if(check > max){
			highest = largeschools[i]; //new max index
			max = check;
		}
	}
	cout << data[highest][1] << endl;
	
	return 0;
}
