int partition(int list[], int left, int right)
{
	int pivot, low, high, temp;
	pivot = list[left];
	low = left;
	high = right + 1;
	
	do {
		do {
			low++;
		} while(list[low]<pivot);
		do {
			high--;
		} while(list[high]>pivot);
		if(low<high) SWAP(list[low], list[high], temp);
	} while (low<high);
	SWAP(list[left], list[high], temp);
	return high;
}

void quickSort(int list[], int left, int right)
{
	if(left<right) {
		int q = partition(list, left, right);
		quickSort(list, left, q-1);
		quickSort(list, q+1, right);
	}
}
