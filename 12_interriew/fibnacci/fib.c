#include <stdlib.h>
#include <stdio.h>

int fib(int n)
{
	if(n < 0) return -1;
	if(0 == n) return 0;
	if(1 == n) return 1;

	return fib(n-1)+fib(n-2);
}

int main()
{
	int n = 0;
	printf("usage: please enter a integer no less than 0:");
	scanf("%d", &n);
	printf("%d\n",n);

	if(n < 0) 
	{
		printf("error input : %d\n ", n);
		return -1;
	}

	printf("fib(%d) = %d\n", n, fib(n));
	return 0;
}
