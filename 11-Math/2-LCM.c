#include <stdio.h>

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	return gcd(m, n%m);
}

int lcm(int n, int m)
{
	int L, G;
	G = gcd(n, m);
	L = (n * m) / G;
	return L;
}

int main(void)
{
	int n, m;
	n = 21;
	m = 28;
	printf("gcd(%d, %d) = %d\n", n, m, gcd(n, m));
	printf("lcm(%d, %d) = %d\n", n, m, lcm(n, m));
	
	
	return 0;
}
