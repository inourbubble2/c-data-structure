#include <stdio.h>


int a[1000001];

void prime(int M, int N) {
	int i, j;
	for(i = 2; i <= N; i++) {
		a[i] = i;
	}
	
	for(i = 2; i <= N; i++) {
		if(a[i] == 0) continue;
		for(j = 2 * i; j <= N; j += i) {
			a[j] = 0;
		}
	}
	int cnt = 0;
	for(i = M; i <= N; i++) {
		if(a[i] != 0) {
			printf("%d ", a[i]);
			cnt += 1;
		}
	}
	printf("\n");
	printf("%d~%d 소수의 개수: %d\n", M, N, cnt);
}

int main(void)
{
	int M, N;
	M = 2;
	N = 300;
	prime(M, N);
	return 0;
}
