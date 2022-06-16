#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define isUppercase(c) ((c)>= 'A' && (c)<= 'Z') 
#define islowercase(c) ((c)>= 'a' && (c) <= 'z')
#define isNumeric(c) ((c)>= '0' && (c) <= '9') 

#define isAlphanumeric(c) (isUppercase(c) || islowercase(c) || isNumeric(c))

typedef enum {
	false,
	true
	}bool;

bool same(char c1, char c2)
{
	if(isUppercase(c1)) c1 = c1 + 'a' - 'A';
	if(isUppercase(c2)) c2 = c2 + 'a' - 'A';
	return c1 == c2;
}

bool isPalindrome(char * s)
{
	int i, j;
	if(NULL == s || '\0' == *s) return true;

	i = 0;
	j = strlen(s) - 1;

	while( i < j)
	{
		while( i<j && !isAlphanumeric(s[i]) ) i++;
		while( i<j && !isAlphanumeric(s[j]) ) j--;
		if(i < j && !same(s[i], s[j]))
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main()
{
	char s[100], *p;
	int i;
	char c;
	
	*p = 'c';
	printf("usage: please enter a string with max len <= 100 ...\n");
	scanf("%s %d %c", p, &i, &c);
	printf("%s %d %c", s, i, c);
	printf("is str: <%s> palindrome? ", s);
	if(isPalindrome(s))

	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	return 0;
}
