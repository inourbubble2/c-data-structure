#include <stdio.h>

int bfMatch(char txt[], char pat[], int txtLen, int patLen)
{
	int pt = 0;
	int pp = 0;
	
	while(pt != txtLen && pp != patLen) {
		if(txt[pt] == pat[pp]) {
			pt++;
			pp++;
		} else {
			pt = pt - pp + 1;
			pp = 0;
		}
	}
	
	if(pp == patLen)
		return pt - pp;
		
	return -1;
}

int main(void)
{
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "bc", bfMatch("abcdefg", "bc", 7, 2));
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "ef", bfMatch("abcdefg", "ef", 7, 2));
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "k", bfMatch("abcdefg", "k", 7, 1));
	
	return 0;
}
