
/*
Sorts the array using Bubble Sort Algorithm
*/
void selection(std::vector<int>& numbers, int n){
    //std::cout << "Selection Sort: ";

	for (int i = n - 1; i >= 0; i--) {
            int max_ = i; // index of maximum entry
		for (int j = 0; j < i; j++) {
			if (numbers[j] > numbers[max_])
                max_ = j;
		}
        std::swap(numbers[i], numbers[max_]);
	}
}
