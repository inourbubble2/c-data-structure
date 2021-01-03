#include <stdio.h>

#define CHAR_MAX_VALUE 65535
int bmMatch(char txt[], char pat[], int txtLen, int patLen)
{
	int pt = 0;
	int pp = 0;
	int skip[CHAR_MAX_VALUE + 1];
	
	for(pt = 0; pt <= CHAR_MAX_VALUE; pt++)
		skip[pt] = patLen;
	for(pt = 0; pt < patLen - 1; pt++)
		skip[pat[pt]] = patLen - pt - 1;
	
	while(pt < txtLen) {
		pp = patLen - 1;
		while(txt[pt] == pat[pp]) {
			if(pp == 0)
				return pt;
			pp--;
			pt--;
		}
		pt += (skip[txt[pt]] > patLen - pp) ? skip[txt[pt]] : patLen - pp;
	}
	
	return -1;
}

int main(void)
{
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "bc", bmMatch("abcdefg", "bc", 7, 2));
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "ef", bmMatch("abcdefg", "ef", 7, 2));
	printf("%s에서 %s의 위치는 : %d\n", "abcdefg", "k", bmMatch("abcdefg", "k", 7, 1));
	
	return 0;
}
