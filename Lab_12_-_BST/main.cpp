#include "BST.cpp"

int main(){
    int cho;
    int x;
    node* root = NULL;
    char end = 'n';
    do {
    cout << "What do you want to do? (1) InOrder, (2) Insert, (3) Find, (4) quit?" << endl;
    cin >> cho;
    switch (cho){
         case 1:
               inorder(root);
               cout << endl;
               break;
         case 2:
               cout << "Enter the element to insert: ";
               cin >> x;
               root = insert_to_bst(root, x);
               break;
         case 3:
               cout << "Enter the element to find: ";
               cin >> x;
               find_in_bst(root, x);
               break;
         case 4:
               end = 'q';
               return 0;
         default:
               break;
        }
    } while (end != 'q');
    return 0;
}
