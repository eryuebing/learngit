#include <stdio.h>
#include <stdlib.h>

// return 1-2+3-4+...+n
int func1(int n)
{
	if(n <= 0)
	{
		printf("input n should be positive integer\n");
		exit(1);
	}

	if(n & 0x01)
	{
		return( ~(n>>1) + 1) + n;
	}
	else
	{
		return ~(n>>1)+1;
	}
}

#define INIT_STR "abcdefghigklmn" 
char str1[] = INIT_STR;
char str2[] = INIT_STR;
const char str3[] = INIT_STR;
const char str4[] = INIT_STR;
char* str5 = INIT_STR;
char* str6 = INIT_STR;

void func2()
{
	/*char str1[] = "abc";
	char str2[] = "abc";
	const char str3[] = "abc";
	const char str4[] = "abc";
	char* str5 = "abc";
	char* str6 = "abc";
*/
	printf("str1 = %p , str2 = %p\n", str1, str2);

	printf("str3 = %p , str4 = %p\n", str3, str4);
	printf("str5 = %p , str6 = %p\n", str5, str6);
}
int main()
{
	printf("func1(4) = %d func1(11) = %d\n", func1(4), func1(11));

	func2();
}
