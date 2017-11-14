
void merge(int arr[], int first, int mid, int last){
    int a = first, c = 0, b = mid, B[last-first+1];

	while(a < mid && b <= last){
		if (arr[a] < arr[b])
            B[c++] = arr[a++];
		else
            B[c++] = arr[b++];
	}

	while( a < mid )
		B[c++] = arr[a++];

	while (b <= last)
		B[c++] = arr[b++];

	for (a=first; a<=last; a++)
		arr[a] = B[a-first];
}
