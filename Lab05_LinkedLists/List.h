// define basic structure of the List Class
#ifndef _LIST_H
#define _LIST_H

#include "Node.cpp"

using namespace std;

class List {
    private:
        node *head; // a pointer to the head of List
        node *tail; // a pointer to the tail of List
    public:
        /*  Constructors   */
        List();
        List(int val); // List initialized with a value
        /*  Other Functions  */
        void insert_at_beginning(int); // inserts a node at the beginning of the List
        void insert_at_end(int); // inserts a node at the tail of the List
        void insert_at_loc(int location, int new_value); // inserts a node at the specified location of the List
        void del(int del_value); // deletes a node with given value
        void display(); // displays the contents of List
        int count(); // counts the number of nodes in List
};
#endif // _LIST_H
