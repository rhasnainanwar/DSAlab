#include "List.h" // import basic structure

#include <iostream>

// creates an empty List
List::List(){
    head = NULL;
    tail = NULL;
}

// creates a List and creates a node with given value
List::List(int val){
    node *temp = new node;
    temp->value = val;
    temp->next = NULL;

    // only one node; that would be head as well as the tail
    head = temp;
    tail = temp;
}

// inserts a new node at the head of List
void List::insert_at_beginning(int val){
    node* new_node = new node;
    new_node->value = val;
    new_node->next = head;

    head = new_node;
    if(!tail) // if List is empty
        tail = new_node;
}

void List::insert_at_end(int val){
    node* new_node = new node;
    new_node->value = val;
    new_node->next = NULL;

    if(!head) // empty
        insert_at_beginning(val);
    if(tail)
        tail->next = new_node; //add next to old tail
    tail = new_node; //make it new tail
}

// insert a new node at the given location
void List::insert_at_loc(int location, int new_value){
    node* new_node = new node;
    new_node->value = new_value;

    if(location > count()){
        cout << "Invalid Location!" << endl;
        return;
    }
    else if(location == 0){
        insert_at_beginning(new_value); // push front
        return;
    }
    else if(location == count()){
        insert_at_end(new_value); // push back
        return;
    }
    node* pointer = head;
    // traverse through the list
    while(--location > 0)
        pointer = pointer->next;

    new_node->next = pointer->next; // cover the next term
    pointer->next = new_node; // attach in
}

// deletes the node with given value, in case of multiple deletes the first occurrence
void List::del(int del_value){
    // if nothing to delete
    if(!head)
       return;

    if(head->value == del_value){
        node* x = head;
        head = head->next;
        delete x;
        return;
    }

    node* pointer = head; // traverse pointer
    node* prev = NULL; // tracks the previous element

    while(pointer->next != NULL){
       if(pointer->next->value == del_value){
            node* x = pointer->next;
            pointer->next = pointer->next->next; // bridge
            delete x;
            break;
       }
       prev = pointer; // current becomes the previous
       pointer = pointer->next;
    }
    // checking last node
    if(pointer->next == NULL && pointer->value == del_value){
        prev->next = NULL; // second-last becomes last
        tail = prev; // this becomes the tail
        delete pointer;
    }
}

// prints values of all nodes from LinkedList
void List::display(){
    if(!head){
        cout << "Empty!" << endl;
        return;
    }
    cout << "Currently the List has: " << endl;
    node* pointer = head; // traverse pointer
    while(pointer != NULL){
       cout << pointer->value << endl;
       pointer = pointer->next;
    }
    cout << "Head: " << head->value << "\t Tail: " << tail->value << "\t Count: " << count() << endl;
}
// counts and returns the number of nodes in list
int List::count(){
    if(!head)
        return 0;
    node* pointer = head; // traverse pointer
    int num = 0;//counter
    while(pointer != NULL){
       num++;
       pointer = pointer->next;
    }
    return num;
}
