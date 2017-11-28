#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void print(int[], int);
void counting_sort(int[], int[], int, int);

int main(){
    int len = 100; // no of elements
    int range = 100; // every element [0, range)
    int numbers[len];
    int sorted[len];

    for(int i = 0; i < len; i++)
        numbers[i] = rand() % range;
    cout << "\nGiven Array: \n";
    print(numbers, len);

    counting_sort(numbers, sorted, len, range);

    cout << "\nSorted Array: \n";
    print(sorted, len);

}

void print(int numbers[], int len){
    for(int k = 0; k < len; k++)
        cout << numbers[k] << " ";
}

void counting_sort(int numbers[], int sorted[], int len, int range){
    int frequency[range];
    for(int i = 0; i <= range; i++)
        frequency[i] = 0;

    for(int i = 0; i < len; i++)
        frequency[ numbers[i] ]++;

    // cumulative
    for(int i = 1; i <= range; i++)
        frequency[i] += frequency[i - 1];

   for(int i = len - 1; i >= 0; i--){
        frequency[ numbers[i] ]--;
        sorted[ frequency[ numbers[i] ] ] = numbers[i];
    }
}
