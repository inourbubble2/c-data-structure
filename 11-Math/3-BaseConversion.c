// 10진수를 2진수로
void to_binary(int n)
{
	if (n != 0) {
		to_binary(n / 2);
		printf("%d", n % 2);
	}
}

// b 베이스의 수 n을 10진수로
int to_10(int n, int b)
{
	int ans, i, temp, length;
	ans = 0;
	temp = n;
	length = 0;
	while(temp > 0) {
		temp /= 10;
		length += 1;
	}
	
	char N[length];
	sprintf(N, "%d", n);
	
	for(i = 0; i < length; i++) {
		ans = ans * b + (N[i] - 48);
	}
	return ans;
	
}

// 10진수의 n을 b 베이스의 수로
int to_b(int n, int b)
{
	int temp, ans, p;
	ans = 0;
	temp = n;
	p = 1;
	while(temp > 0) {
		ans += temp % b * p;
		temp /= b;
		p *= 10;
	}
	return ans;
}
