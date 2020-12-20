void selectionSort(int list[], int n)
{
	int i, j, least, temp;
	for(int i = 0; i < n-1; i++) {
		least = i;
		for(j = i + 1; j < n; j++)
			if(list[j] < list[least]) least = j;
		if(i != least) //최소값이 자신일 때 자료이동을 하는 것을 방지
			SWAP(list[i], list[least], temp);

	}	
}
