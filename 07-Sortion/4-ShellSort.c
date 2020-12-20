void insertionSort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for(i = first + gap; i < last; i = i + gap) {
		key = list[i];
		for(j = i - gap; j >= first && list[j] > key; j = j - gap) {
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}

void shellSort(int list[], int n)
{
	int i, gap;
	for(gap = n / 2; gap>0; gap = gap/2) {
		if((gap % 2) == 0) gap++;
		for(i = 0; i < gap; i++) 
			insertionSort(list, i, n-1, gap);
	}
}
