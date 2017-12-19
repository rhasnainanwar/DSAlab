#include "heap.cpp"

int main(){

    vector<int> heap;
    //heap.push_back(-1); // one-indexed

    int arr[]= {5,4,15,8,17,13,11,2};
    int arrSize = 8;
    cout<<"------------------"<<endl;
    cout<<"Operations on Heap"<<endl;
    cout<<"------------------"<<endl;
    cout<<"0. Form Heap from Array"<<endl;
    cout<<"1. Insert Element"<<endl;
    cout<<"2. Pop Element"<<endl;
    cout<<"3. Extract Minimum Element"<<endl;
    cout<<"4. Print Heap"<<endl;
    cout<<"5. Height of Heap"<<endl;
    cout<<"6. Number of elements in Heap"<<endl;
    cout<<"7. Is heap Empty?"<<endl;
    cout<<"8. Exit"<<endl;

    int choice, element;
    bool cont = true;
    while(cont){
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                build_heap(heap, arr, arrSize);
                cout << "Values inserted, here's your heap: ";
                print(heap);
                break;
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>element;
                push(heap, element);
                break;
            case 2:
                pop(heap);
                cout << "Top removed, here's your heap: ";
                print(heap);
                break;
            case 3:
                cout << "Heap Top: " << top(heap) << endl;
                break;
            case 4:
                cout<<"Displaying elements of Heap:  ";
                print(heap);
                break;
            case 5:
                cout << "Heap Height: " << height(heap) << endl;
                break;
            case 6:
                cout << "Heap Size: " << size(heap) << endl;
                break;
            case 7:
                if(isEmpty(heap))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                break;
            case 8:
                cont = false;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }
    return 0;
}
