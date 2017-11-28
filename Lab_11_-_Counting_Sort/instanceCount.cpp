#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void print(int[], int);
void countInstance(int[], int[], int);

int main(){
    int len = 10;
    int range = 10; // elements [0, 100)

    int numbers[len];
    for(int i = 0; i < len; i++)
        numbers[i] = rand() % range;
    cout << "RANGE: " << range << "\tNo. of ELEMENTS: " << len << endl;
    cout << "Given array:" << endl;
    print(numbers, len);

    int frequency[range];
    for(int i = 0; i < range; i++)
        frequency[i] = 0;

    countInstance(numbers, frequency, len);
    cout << "\nFrequency array:" << endl;
    print(frequency, range);
    return 0;
}

void print(int values[], int len){
    for(int i = 0; i < len; i++)
        cout << values[i] << " ";
}

void countInstance(int numbers[], int freq[], int len){
    for(int i = 0; i < len; i++)
        freq[ numbers[i] ]++;
}
