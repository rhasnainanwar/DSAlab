/* BUBLE SORT */
/*
Sorts the array using Bubble Sort Algorithm
*/
void bubble(std::vector<int>& numbers, int n){
    //std::cout << "Bubble Sort: ";
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (numbers[j] > numbers[j + 1])
				std::swap(numbers[j], numbers[j + 1]);
		}
	}
}
