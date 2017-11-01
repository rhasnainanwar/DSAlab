#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "bubble.cpp"
#include "selection.cpp"
#include "insertion.cpp"

//prototype
void print(std::vector<int>&, int);

int main() {
    std::srand(time(NULL));
    /* AVERAGE TIME */
    double times[] = {0.0, 0.0, 0.0}; //record time

    for(int i = 100; i <= 1000000; i*=10){
        std::vector<int> numbers_1;
        std::vector<int> numbers_2;
        std::vector<int> numbers_3;
        //random filling
        for (int j = 0; j < i; ++j){
            int num = rand() % 100 + 1; // one copy for each algo
            numbers_1.push_back(num);
            numbers_2.push_back(num);
            numbers_3.push_back(num);
        }
        std::cout << "Input size: " << i << "\n";
        clock_t tStart = clock();
        bubble(numbers_1, i);
        clock_t tMid = clock();

        times[0] += (double)(tMid - tStart);
        std::cout << "Bubble sort: " << (double)(tMid - tStart) << std::endl;


        selection(numbers_2, i);
        clock_t tMid2 = clock();

        times[1] += (double)(tMid2 - tMid);
        std::cout << "Selection sort: " << (double)(tMid2 - tMid) << std::endl;

        insertion(numbers_3, i);
        times[2] += (double)(clock() - tMid2);
        std::cout << "Insertion sort: " << (double)(clock() - tMid2) << std::endl;
        std::cout << "\n";
    }
    std::cout << "Average for Bubble Sort" << times[0] / 5.0 << " ms" << std::endl;
    std::cout << "Average for Selection Sort" << times[1] / 5.0 << " ms" << std::endl;
    std::cout << "Average for Insertion Sort" << times[2] / 5.0 << " ms" << std::endl;

    /* Best Case */
    std::vector<int> numbers;
    for (int j = 0; j < 1000; ++j)
        numbers.push_back(rand() % 100 + 1); // one copy for each algo

    // already sorted
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Best Cases: \n";
    clock_t tStart = clock();
    bubble(numbers, 1000);
    clock_t tMid = clock();
    std::cout << "Bubble sort: " << (double)(tMid - tStart) << std::endl;

    selection(numbers, 1000);
    clock_t tMid2 = clock();
    std::cout << "Selection sort: " << (double)(tMid2 - tMid) << std::endl;

    insertion(numbers, 1000);
    std::cout << "Insertion sort: " << (double)(clock() - tMid2) << std::endl;

    /* Worst Case */
    std::cout << "\nWorst Cases: \n";
    std::reverse(numbers.begin(), numbers.end()); // reverse sort for each case

    tStart = clock();
    bubble(numbers, 1000);

    std::reverse(numbers.begin(), numbers.end());

    tMid = clock();
    std::cout << "Bubble sort: " << (double)(tMid - tStart) << std::endl;

    selection(numbers, 1000);

    std::reverse(numbers.begin(), numbers.end());
    tMid2 = clock();
    std::cout << "Selection sort: " << (double)(tMid2 - tMid) << std::endl;

    insertion(numbers, 1000);
    std::cout << "Insertion sort: " << (double)(clock() - tMid2) << std::endl;

	return 0;
}

/*
Prints the content of an array
Input: Reference to the array
Output: None
Passed Back: None
*/
void print(std::vector<int>& numbers, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n";
}
