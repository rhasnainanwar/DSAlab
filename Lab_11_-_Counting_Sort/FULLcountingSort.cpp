#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void print(string[], int);
void full_counting_sort(int[], string[], string[], int, int);

int main(){
    int len; // no. of elements
    cin >> len;
    // for inputs
    int x;
    string y;
    int numbers[len];
    string words[len];

    for(int i = 0; i < len/2; i++){
        cin >> x;
        numbers[i] = x;
        cin >> y;
        words[i] = "-";
    }
    for(int i = len/2; i < len; i++){
        cin >> x;
        numbers[i] = x;
        cin >> y;
        words[i] = y;
    }
    int range = *std::max_element(numbers,numbers+len); // every element [0, range]
    string sorted[len]; // passed back
    full_counting_sort(numbers, words, sorted, len, range);
    print(sorted, len);
    return 0;
}

void print(string words[], int len){
    for(int i = 0; i < len; i++)
        cout << words[i] << " ";
}

void full_counting_sort(int numbers[], string words[], string sorted[], int len, int range){
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
        sorted[ frequency[ numbers[i] ] ] = words[i];
    }
}
