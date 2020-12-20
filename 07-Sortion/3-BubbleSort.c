void bubbleSort(int list[], int n)
{
	int i, j, temp;
	for(i = n - 1; i > 0; i--) {				//리스트의 끝을 결정 
		for(j = 0; j < i; j++) 					
			if(list[j]>list[j+1]) 
				SWAP(list[j], list[j+1], temp);
	}
}
