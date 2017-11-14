#include <iostream>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include "merge_sort.cpp"
using namespace std;

int main(){
    srand(time(NULL));
    /* for(int len = 100; len <= 100000; len*=10){
        int numbers[len];

        for(int i = 0; i < len; i++)
            numbers[i] = rand() % 100 + 1;

        clock_t time = clock();
        merge_sort(numbers, 0, len-1);
        cout << "For " << len << "\nTime is: " << float(clock() - time)/CLOCKS_PER_SEC << endl;
    } */

    /* FOR BEST AND WORST CASE */
    int numbers[100];
    for(int i = 0; i < 100; i++)
        numbers[i] = rand() % 100 + 1;
    sort(numbers, numbers+100, less<int>());

    clock_t time = clock();
    merge_sort(numbers, 0, 99);
    cout << "For ascending, Time is: " << float(clock() - time)/CLOCKS_PER_SEC << endl;

    sort(numbers, numbers+100, greater<int>());

    time = clock();
    merge_sort(numbers, 0, 99);
    cout << "For descending, Time is: " << float(clock() - time)/CLOCKS_PER_SEC << endl;

    return 0;
}
