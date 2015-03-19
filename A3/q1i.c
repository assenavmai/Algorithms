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
		for(j = 1; j < n; j++)
		{
			sum++;
		}
	}

	finish = clock();

	elapsed = (double)(finish - start) / CLOCKS_PER_SEC * 1000;

	printf("(i) Sum for value %d: %d\n", n, sum);
	printf("Time: %f\n\n", elapsed);

	n = 20;
	sum = 0;

	start = clock();

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			sum++;
		}
	}

	finish = clock();

	elapsed = (double)(finish - start) / CLOCKS_PER_SEC * 1000;

	printf("(i) Sum for value %d: %d\n", n, sum);
	printf("Time: %f\n\n", elapsed);

	n = 30;
	sum = 0;
	start = clock();

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			sum++;
		}
	}

	finish = clock();

	elapsed = (double)(finish - start) / CLOCKS_PER_SEC * 1000;

	printf("(i) Sum for value %d: %d\n", n, sum);
	printf("Time: %f\n\n", elapsed);

	n = 50;
	sum = 0;

	start = clock();

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			sum++;
		}
	}

	finish = clock();

	elapsed = (double)((finish - start) / CLOCKS_PER_SEC) * 1000;

	printf("(i) Sum for value %d: %d\n", n, sum);
	printf("Time: %f\n\n", elapsed);

	n = 100000;
	sum = 0;
	
	start = clock();

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			sum++;
		}
	}

	finish = clock() - start;

	elapsed = (float)((finish) / CLOCKS_PER_SEC) * 1000;

	printf("(i) Sum for value %d: %d\n%d\n", n, sum,finish);
	printf("Time: %f\n\n", (float)((finish) / CLOCKS_PER_SEC) * 1000);

	return 0;
}
