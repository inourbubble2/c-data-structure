// 재귀적인 방법, O(n)
int factorial(int n)
{
	if(n == 1){
		printf("1\n");
		return 1;
	}
	int fc = factorial(n - 1);
	printf("%d * %d\n", n, fc);
	return n * fc;
}

// 비재귀적인 방법
int factorial2(int n)
{
	int fc = 1;
	for(int i = 1; i <= n; i++) {
		fc *= i;
		printf("%d * %d\n", i, fc);
	}
	return fc;
}
