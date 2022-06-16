#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int fib_helper(int n, int* rsltArray)
{
	if(0 == n) return 0;
	if(1 == n) return 1;

	assert(rsltArray);
	if(-1 != rsltArray[n]) return rsltArray[n];
	
	return rsltArray[n] = fib_helper(n-1, rsltArray) + fib_helper(n-2, rsltArray);

}

int fib(int n)
{
	int * rsltArray = NULL;
	int ret;

	if(n < 0) return -1;
	if(0 == n) return 0;
	if(1 == n) return 1;

	rsltArray = malloc(sizeof(int)*(n+1));
	assert(rsltArray);
	memset(rsltArray, -1, sizeof(int)*(n+1));

	ret = fib_helper(n, rsltArray);
	
	free(rsltArray);
	return ret;
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
