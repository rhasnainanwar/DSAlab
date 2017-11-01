/*
Sorts the array using Insertion Sort Algorithm
*/
void insertion(std::vector<int>& numbers, int n){
    //std::cout << "Insertion Sort: ";
	for (int i = 1; i < n - 1; i++) {
        int key = numbers[i];
        int j = i - 1;

		while(j >= 0 && key < numbers[j]){
            numbers[j + 1] = numbers[j];
            j--;
		}
		numbers[j+1] = key;
	}
}
