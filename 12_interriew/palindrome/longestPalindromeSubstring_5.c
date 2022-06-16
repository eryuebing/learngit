#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPldrSubstr(char *s)
{
	int len, longest = 0,sublen, mid, left, right;
	char *lgstSubstr = NULL, *rslt = NULL;

	if(NULL == s || '\0' == *s)return s;

	mid = 0;
	len = strlen(s);

	while(s[mid] != '\0')
	{
		left = mid - 1;
		right = mid;
		sublen = 0;
		while(left >= 0 && right <= len - 1 && s[left] == s[right])
		{
			sublen += 2;
			left--;
                	right++;
		}
		if(sublen > longest)
		{
			longest = sublen;
			lgstSubstr =&(s[left + 1]); 
		}
		printf("even: mid %d, longest:%d lgstSubstr = %p\n", mid, longest, lgstSubstr);
		
		left = mid - 1;
                right = mid + 1;
                sublen = 0;
                while(left >= 0 && right <= len - 1 && s[left] == s[right])
                {
                        sublen += 2;
			left--;
                	right++;
                }
                if(sublen + 1 > longest)
                {
                        longest = sublen + 1;
                        lgstSubstr =&(s[left + 1]);
                }

		printf("odd: mid %d, longest:%d lgstSubstr = %p\n", mid, longest, lgstSubstr);
		mid++;
	}

	rslt = malloc(sizeof(char)*(longest + 1));
	memcpy(rslt, lgstSubstr,sizeof(char)*longest);
	rslt[longest] = '\0';

	return rslt;
}

int main()
{
	char s[100], *substr = NULL;
	printf("usage：please input a string with length less than 100:");
	scanf("%s", s);
	printf("str = %s\n", s);
	substr = longestPldrSubstr(s);
	printf("str: %s  longest palindrom substring: %s\n", s, substr);
	if(substr) free(substr);
	return 0;

}
