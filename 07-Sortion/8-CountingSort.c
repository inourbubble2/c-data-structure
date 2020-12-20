void countingSort(int array[], int n, int b)
{
	int count[n];
	int temp;
	
	for(int i = 0; i < b; i++) {
		count[i] = 0;
	}	
	
	for(int i = 0; i < n; i++) {
		count[array[i] - 1]++;
	}	

	for(int i = 0; i < b; i++){
		if(count[i] != 0) {
			for(int j = 0; j < count[i]; j++) {
				printf("%d", i + 1);
			}
		}
	}	
}
