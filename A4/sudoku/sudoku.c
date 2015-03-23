#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*you will have to change this manually depending on the dimensions
of the puzzle*/
#define MAXSIZE 9


typedef enum{false, true} Boolean;

Boolean existInRow(int row, int num);
void printSolution();
Boolean existInCol(int col, int num);
void solveSudoku(int row, int col);

int grid[MAXSIZE][MAXSIZE];

/*checks if the number is already in the row
	if so, return true else false*/
Boolean existInRow(int row, int num){

	int col;

	for(col = 0; col < MAXSIZE; col++)
	{
		if(grid[row][col] == num)
		{
			return true;
		}
	}

	return false;
}

/*checks if the number is the column 
	if so, return true else false*/
Boolean existInCol(int col, int num){

	int row;

	for(row = 0; row < MAXSIZE; row++)
	{
		if(grid[row][col] == num)
		{
			return true;
		}
	}

	return false;
}

/*Checks if the number exists in a single box*/
Boolean existInBox(int row, int col, int num){
	int i,j, root;

	root = sqrt(MAXSIZE);

	row = (row/root)*root;
	col = (col/root)*root;

	for(i = 0; i < root; i++)
	{
		for(j = 0; j < root; j++)
		{
			if(grid[row+i][col+j] == num)
			{
				return true;
			}
		}
	}

	return false;
}

/*solves the puzzle*/
void solveSudoku(int row, int col){

	if(row == MAXSIZE)
	{
		printSolution();
	}
	if(grid[row][col] == 0)/*if the space id empty*/
	{
		int num;

		/*go through possible numbers 1 - maxsize*/
		for(num = 1; num <= MAXSIZE; num++)
		{
			/*if the number in not the in row, column and box then add it*/
			if(!existInRow(row, num) && !existInCol(col, num) && !existInBox(row, col, num))
			{
				grid[row][col] = num;

				/*if we are not at the last column, go to the next to solve*/
				if(col < MAXSIZE - 1)
				{
					solveSudoku(row, col+1);
				}
				else /*go to the next row and start to solve*/
				{
					solveSudoku(row+1, 0);
				}
			}
			/*backtrack by making it empty again*/
			grid[row][col] = 0;
		}
	}
	else
	{
		if(col < MAXSIZE - 1)
		{
			solveSudoku(row, col+1);
		}
		else
		{
			solveSudoku(row+1, 0);
		}
	}
}

/*output the solution to a file*/
void printSolution(){

	int row, col;
	FILE * out;

	out = fopen("output.sudoku", "w");

	/*printf("\n");
	printf("Solution: \n\n");*/
	for(row = 0; row < MAXSIZE; row++)
	{
		for(col = 0; col < MAXSIZE; col++)
		{
			/*printf(" %d ", grid[row][col]);*/
			fprintf(out, " %d ", grid[row][col]);
		}
		/*printf("\n");*/
		fprintf(out, "\n");
	}
}

int main(int argc, char const *argv[])
{
	int i,j;
	FILE * f;

	if((f = fopen("input.sudoku", "r")) == NULL)
	{
		fprintf(stderr, "%s\n", "File could not be opened.");
		exit(1);
	}

	for(i = 0; i < MAXSIZE; i++)
	{
		for(j = 0; j < MAXSIZE; j++)
		{
			fscanf(f, "%d", &grid[i][j]);
		}
	}

	fclose(f);

	/*start at first spot in grid*/
	solveSudoku(0,0);

	return 0;
}