#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sort(int arr[], int len);

int main(int argc, char const *argv[])
{
	char firstline[1024];
	char line[1024];
	int frequency[101] = {0};
	int num, i, j, counter, index, maximized, freqAm;
	unsigned int highAdd, lowAdd;
	double elapsed = 0;
	clock_t start, finish;
	FILE * f;

	f = fopen("Test.txt", "r");

	if(f == NULL)
	{
		fprintf(stderr, "%s\n", "Need a file name.");
		exit(1);
	}

	num = 0;
	highAdd = 0;
	lowAdd = 0;
	counter = 0;
	j = 0;
	maximized = 0;

	srand(time(NULL));
	start = clock();
	
	/*this reads the file and counts the frequency*/
	fgets(line, sizeof(line),f);
	line[strlen(line) - 1] = '\0';
	num = atoi(line);
	counter = num;
	index = num/2;

	while(fgets(line, sizeof(line), f) != NULL)
	{
		line[strlen(line) - 1] = '\0';
		num = atol(line);

		frequency[num]++;
	}

	/*for(i = 100; i > 0; i--)
	{
		printf("Frequency of %d: %d\n", i, frequency[i]);
	}*/
	printf("\nFrequency of:\n");
	printf("15: %d\n", frequency[15]);
	printf("27: %d\n", frequency[27]);
	printf("54: %d\n", frequency[54]);
	printf("89: %d\n", frequency[89]);

	j = 100;
	

	for(i = 0; i < index; i++)
	{
		while(j > 0 && counter != 0)
		{
			freqAm = frequency[j];
			if(frequency[j] > 0 && counter > index)
			{
				highAdd += j * frequency[j];
				frequency[j] = 0;
				counter -= freqAm;
			}

			if(frequency[j] > 0 && counter <= index)
			{
				lowAdd += j * frequency[j];
				counter -= freqAm;
			}
			
			j--;
		}
	}

	maximized = highAdd - lowAdd;

	finish = clock();
    
    elapsed = (double)(finish - start) / CLOCKS_PER_SEC;

	printf("\n%d - %d = %d\n\n", highAdd, lowAdd, maximized);
	printf("time = %f \n\n", elapsed);

	return 0;
}
