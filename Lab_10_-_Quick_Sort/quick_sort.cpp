using namespace std;
int part(int numbers[], int p, int r, int& partitionCount){
    partitionCount++;
    int i, j;
	i = p - 1;
	int x = numbers[ (p+r)/2 + 1]; //pivot

	for(j = p; j < r; j++){
		if(numbers[j] <= x){
			i++;
			swap(numbers[i], numbers[j]);
		}
	}

	numbers[r] = numbers[i + 1];
	numbers[i + 1] = x;

	return i + 1;
}

void quick_sort(int numbers[], int low, int high, int& partitionCount){
    if(low < high){
		int q = part(numbers,low,high, partitionCount);
		quick_sort(numbers,low, q - 1, partitionCount);
		quick_sort(numbers,q + 1,high, partitionCount);
	}
}
