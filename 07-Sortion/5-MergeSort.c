void merge(int list[], int left, int mid, int right)
{
	int i = left;	//정렬된 왼쪽 리스트에 대한 인덱스 
	int j = mid+1;	//정렬된 오른쪽 리스트에 대한 인덱스 
	int k = left;	//k는 정렬될 리스트에 대한 인덱스
	
	//분할 정렬된 리스트의 합병 
	while(i<=mid && j <= right) {
		if(list[i]<list[j]) {		//오른쪽 리스트의 첫번째 레코드가 왼쪽 리스트보다 크다면 
			sorted[k] = list[i];	//정렬된 리스트에 왼쪽 리스트의 첫번째 값을 넣는다 
			k++; 
			i++;
		} else {					
			sorted[k] = list[j];
			k++;
			j++;
		}
	}
	if(i>mid) //남아있는 레코드의 일괄 복사 
		for(int l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 	 //남아있는 레코드의 일괄 복사 
		for(int l = i; l <= mid; l++)
			sorted[k++] = list[l];
			
	for(int l = left; l <= right; l++)	//배열 재복사 
		list[l] = sorted[l];
}

void mergeSort(int list[], int left, int right)
{
	if(left < right) {
		int mid = (left+right)/2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
