#include "merge.cpp"

void merge_sort(int arr[], int first, int last){
    int mid;
    if(first < last){
        mid = (first + last)/2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid+1, last);
        merge(arr, first, mid+1, last);
    }
}
