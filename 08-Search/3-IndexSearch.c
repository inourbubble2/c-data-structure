int indexSearch(int key, int n)
{
	int i, low, high;
	
	//키 값이 리스트 범위 내의 값이 아니면 탐색 종료 
	if(key<list[0] || key>list[n-1])
		return -1;
	
	//인덱스 테이블을 조사하여 해당 키의 구간 설정
	for(i = 0; i < INDEX_SIZE; i++)
		if(indexList[i].key <= key && indexList[i + 1].key >key) 
			break;
	if(i == INDEX_SIZE) {		//인덱스 테이블의 끝이면 (인덱스 탐색을 실패했을 시) 
		low = indexList[i-1].index;
		high = n;
	} else {
		low = indexList[i].index;
		high = indexList[i+1].index;
	}
	//예상되는 범위만 순차탐색 
	return seqSearch(key, low, high);
}
