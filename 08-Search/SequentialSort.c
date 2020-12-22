int seqSearch(int key, int low, int high)
{
	for(int i = low; i <= high; i++) 
		if(list[i] == key)
			return i;
	return -1;
}
