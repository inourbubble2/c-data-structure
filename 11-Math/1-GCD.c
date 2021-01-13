#include <stdio.h>

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	return gcd(m, n%m);
}

int main(void)
{
	int n, m;
	n = 21;
	m = 28;
	printf("fac(%d, %d) = %d", n, m, gcd(n, m));
	
	return 0;
}
