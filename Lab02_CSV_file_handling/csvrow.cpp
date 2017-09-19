//dependencies
#include <vector>
#include <sstream>
#include <iostream>
using namespace std; //standard namespace

class CSVRow {
    vector<string> m_data; //a vector to hold record of one row

	//function declaration
	public:
		//returns the size of vector i.e., no. of record in one row
		size_t size() const {
			return m_data.size(); //return size of vector
		}
		//reads next line from input stream and adds it to the vector
		void readNextLine(istream& str){
			string line; //temporary variable to store one line at a time
			getline(str, line); //read row from stream
			stringstream lineStream(line); //making the line extractable

			string cell;
			m_data.clear(); //clear vector to restore cell-by-cell

			while (getline(lineStream, cell, ','))
				m_data.push_back(cell); //store cell-by-cell
		}
		
		vector<string> getData(){
		    return m_data;
		}
};