// 재귀적인 방법 O(2^n)
int fib(int n)
{
	if (n <= 2)
		return 1;
	return fib(n - 2) + fib(n - 1);
}

// 비재귀적인 방법 O(n)
int fib2(int n)
{
	int prev, prevprev;
	prev = 1; 
	prevprev = 1;
	int ans = 0;
	for(int i = 3; i <= n; i++) {
		ans = prev + prevprev;
		prevprev = prev;
		prev = ans;
	}
	return ans;
}
