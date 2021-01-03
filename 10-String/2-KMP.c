#include <stdio.h>

int kmpMatch(char txt[], char pat[], int txtLen, int patLen)
{
	int pt = 0;
	int pp = 0;
	int skip[patLen + 1];
	
	skip[pt] = 0;
	while(pt != patLen) {
		if (pat[pt] == pat[pp])
			skip[++pt] = pp;
		else if (pp == 0)
			skip[++pt] = pp;
		else
			pp = skip[pp];
	}
	
	pt = pp = 0;
	while(pt != txtLen && pp != patLen) {
		if(txt[pt] == pat[pp]) {
			pt++;
			pp++;
		} else if (pp == 0) {
			pt++;
		} else {
			pp = skip[pp];
		}
	}
	
	
	if(pp == patLen)
		return pt - pp;
		
	return -1;
}

int main(void)
{
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "bc", kmpMatch("abcdefg", "bc", 7, 2));
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "ef", kmpMatch("abcdefg", "ef", 7, 2));
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "k", kmpMatch("abcdefg", "k", 7, 1));
	
	return 0;
}
