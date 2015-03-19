#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int sum, i, j, k, n;

	sum  = 0;
	n = 10;

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < (int) pow((double) i, 3); j++)
		{
			for(k = 1; k < j; k++)
			{
				sum++;
			}
		}
	}

	printf("(iii) Sum for value %d: %d\n", n, sum);

	sum  = 0;
	n = 20;

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < (int) pow((double) i, 3); j++)
		{
			for(k = 1; k < j; k++)
			{
				sum++;
			}
		}
	}

	printf("(iii) Sum for value %d: %d\n", n, sum);

	n = 30;
	sum = 0;
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < (int) pow((double) i, 3); j++)
		{
			for(k = 1; k < j; k++)
			{
				sum++;
			}
		}
	}

	printf("(iii) Sum for value %d: %d\n", n, sum);

	n = 50;
	sum = 0;

	for(i = 1; i < n; i++)
	{
		for(j = 1; j < (int) pow((double) i, 3); j++)
		{
			for(k = 1; k < j; k++)
			{
				sum++;
			}
		}
	}

	printf("(iii) Sum for value %d: %d\n", n, sum);

	n = 100;
	sum = 0;
	
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < (int) pow((double) i, 3); j++)
		{
			for(k = 1; k < j; k++)
			{
				sum++;
			}
		}
	}

	printf("(iii) Sum for value %d: %d\n", n, sum);

	return 0;
}
