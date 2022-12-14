#include "sandpiles.h"
#include <stdio.h>

static void print_grid(int grid[3][3]);
int check_grid(int grid[3][3]);
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;
	int grid_changes[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j]; }
	if ((check_grid(grid1)) > 0)
		print_grid(grid1);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] - grid_changes[i][j] > 3)
			{
				grid_changes[i][j] = 0;
				if (i > 0)
				{
					grid1[i - 1][j] += 1, grid_changes[i - 1][j] += 1; }
				if (j > 0)
				{
					grid1[i][j - 1] += 1, grid_changes[i][j - 1] += 1; }
				if (i < 2)
				{
					grid1[i + 1][j] += 1, grid_changes[i + 1][j] += 1; }
				if (j < 2)
				{
					grid1[i][j + 1] += 1, grid_changes[i][j + 1] += 1; }
				grid1[i][j] -= 4; }}
		if (i == 2)
		{
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
					grid_changes[i][j] = 0;
			}
			if (check_grid(grid1) > 0)
			{
				print_grid(grid1);
				i = -1; }
		}
	}
}


/**
 * check_grid - Checks if grid is stable
 * @grid: grid to check
 *
 * Return: number of changes to mak
 */
int check_grid(int grid[3][3])
{
	int i = 0, j = 0, changes = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				changes++;
		}
	}
	return (changes);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
