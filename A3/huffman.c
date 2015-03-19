#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char firstLine[1024];
	char line[1024];
	int frequency[27];
	FILE * f;

	f = fopen("Huffman.txt", "r");

	if(f == NULL)
	{
		fprintf(stderr, "%s\n", "File cannot be opened.");
		exit(1);
	}

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
	return 0;
}