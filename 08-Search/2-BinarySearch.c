// Binary Search with Recursion
int binarySearch(int key, int low, int high)
{
	int middle;
	if(low <= high) {
		middle = (low + high) / 2;
		if(key == list[middle])
			return middle;
		else if(key < list[middle])
			return binarySearch(key, low, middle - 1);
		else 
			return binarySearch(key, middle + 1, high);
	}
	return -1;
}

// Binary Search with Iteration
int binarySearch2(int key, int low, int high)
{
	int middle;
	while(low <= high) {
		middle = (low + high) / 2;
		if(list[middle] == key) return middle;
		else if(key > list[middle]) 
			low = middle + 1;
		else 
			high = middle - 1;
	}
	return -1;
}
