#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int sum, i, j, n;
	double elapsed;
	clock_t start, finish;

	sum  = 0;
	n = 10;

	start = clock();

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < i; j++)
		{
			sum++;
		}
	}

	finish = clock();

	elapsed = (double)(finish - start) / CLOCKS_PER_SEC * 1000;
	
	printf("(ii) Sum for value %d: %d\n", n, sum);

	n = 20;
	sum = 0;

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < i; j++)
		{
			sum++;
		}
	}

	printf("(ii) Sum for value %d: %d\n", n, sum);

	n = 30;
	sum = 0;

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < i; j++)
		{
			sum++;
		}
	}

	printf("(ii) Sum for value %d: %d\n", n, sum);

	n = 50;
	sum = 0;
	
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < i; j++)
		{
			sum++;
		}
	}

	printf("(ii) Sum for value %d: %d\n", n, sum);

	n = 100;
	sum = 0;
	
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < i; j++)
		{
			sum++;
		}
	}

	printf("(ii) Sum for value %d: %d\n", n, sum);

	return 0;
}
