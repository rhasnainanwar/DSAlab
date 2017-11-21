#include <iostream>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include "quick_sort.cpp"

int main(){
    srand(time(NULL));
    /*int numbers[] = {56, 46, 64, 89, 468, 78};
    int len = 6;
    for(int i = 0; i < 6; i++)
           cout << numbers[i] << " ";
    cout << endl;
    quick_sort(numbers, 0, len - 1);

    for(int i = 0; i < 6; i++)
           cout << numbers[i] << " ";
    */
    cout << "Pivot point: Median\n\n";
    for(int len = 10; len <= 100000; len*=10){
        int numbers[len];
        for(int i = 0; i < len; i++)
            numbers[i] = rand() % 100 + 1;
        int partitionCount = 0;
        cout << "For n = " << len << ":" << "\n";
        quick_sort(numbers, 0, len-1, partitionCount);
        cout << "Partitions = " << partitionCount << "\n" << endl;
    }

    return 0;
}
