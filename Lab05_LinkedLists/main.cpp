#include "List.cpp"

int main(){
    List list;
	int choice = -1;

    cout << "Menu:" << endl;
	cout << "1: Insert at beginning" << endl;
	cout << "2: Insert at the end" << endl;
	cout << "3: Insert at a location" << endl;
	cout << "4: Delete a node" << endl;
	cout << "5: Display the List" << endl;
	cout << "6: Count the size of List" << endl;
    int loc, val;
    // inputs and operations
	do {
		cout << "Enter choice from menu or -1 to End: ";
		cin >> choice;
		switch (choice) {
		case 1:
		    cout << "Enter the value to insert: ";
		    cin >> val;
			list.insert_at_beginning(val);
			break;
        case 2:
            cout << "Enter the value to insert: ";
            cin >> val;
            list.insert_at_end(val);
            break;
		case 3:
		    cout << "Enter the value to insert: ";
		    cin >> val;
		    cout << "Enter the location to insert: ";
		    cin >> loc;
			list.insert_at_loc(loc, val);
			break;
		case 4:
			cout << "Enter the value to delete: ";
		    cin >> val;
            list.del(val);
			break;
		case 5:
			list.display();
			break;
		case 6:
			cout << "Count: " << list.count() << endl;
			break;
        }
	} while (choice != -1);

    return 0;
}
