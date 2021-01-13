int lcm(int a, int b)
{
	int g;
	g = gcd(a, b);
	return a * b / g; // L = (A * B) / G
}
