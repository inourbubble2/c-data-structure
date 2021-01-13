// 재귀적인 방법
int gcd(int a, int b)
{
    if (b == 0)
        return a;            // b가 0이 되었을 때의 a가 최대공약수임
    else
        return gcd(b, a%b);
}

// 비재귀적인 방법
int gcd2(int a, int b)
{
    while(b != 0)  
    {
    	
        int r = a % b;
        a = b;
        b = r;
    }
    return a;        // b가 0이 되었을 때의 a가 최대공약수임
}
