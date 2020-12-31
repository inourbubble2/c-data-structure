#define M 997
int hashFunction1(int key)
{
	int hashIndex = key % M;
	if(hashIndex < 0)
		hashIndex += M;
	return hashIndex;
}

int hashFunction(char *key) 
{
	int hashIndex = 0;
	int g = 31;
	while(*key)
		hashIndex = g * hashIndex + *key++;
	return hashIndex;
}
