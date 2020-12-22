int seqSearch(int key, int low, int high)
{
	for(int i = low; i <= high; i++) 
		if(list[i] == key)
			return i;
	return -1;
}

// Improved Sequential Search
int seqSearch2(int key, int low, int high)
{
	int i;
	list[high + 1] = key;
	for(i = low; list[i] != key; i++)
		;
	if(i == (high + 1)) return -1;
	return i;
}
