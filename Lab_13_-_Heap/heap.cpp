#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int size(vector<int>& heap){
    return heap.size() - 1;
}

void adjust_heap(vector<int>& heap){
    int n = size(heap);
    int k;
    for(int i = n; i > 1; i--){
        k = i;
        while(k/2 > 0){
            if(heap[k] < heap[k/2])
                swap(heap[k], heap[k/2]);
            else // greater than or equal to parent, correct order
                break;
            k /= 2;
        }
    }
}

void push(vector<int>& heap, int val){
    heap.push_back(val);
    adjust_heap(heap);
}

void heapifydown(vector<int>& heap, int in){

    int child = in*2;
    int child1 = 2*in + 1;
    if (child >= 1 && child1 >= 1 && heap[child] > heap[child1])
    {
       child = child1;
    }
    if (child > 1 && heap[in] > heap[child])
    {
        swap(heap[child], heap[in]);
        heapifydown(heap, child);
    }
}

void pop(vector<int>& heap){
    heap[1] = heap[ size(heap) ];
    heap.pop_back();
    heapifydown(heap, 1);
}


void print(vector<int>& heap){
    int n = size(heap);
    for(int i = 1; i <= n; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int top(vector<int>& heap){
    return heap[1];
}

bool isEmpty(vector<int>& heap){
    return heap.size() <= 1;
}

int height(vector<int>& heap){
    return floor(log2(size(heap)));
}

void build_heap(vector<int>& heap, int arr[], int n){
    for(int i = 0; i < n; i++)
        push(heap, arr[i]);
}
