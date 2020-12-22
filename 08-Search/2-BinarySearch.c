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
