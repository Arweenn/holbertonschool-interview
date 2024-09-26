#include "sandpiles.h"

/**
 * print_sandpile - Print 3x3 grid.
 * @grid: 3x3 grid.
 * Return: Nothing.
 */

void print_sandpile(int grid[3][3])
{
	int i, j;

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

/**
 * is_stable - Check if a sandpile is stable.
 * @grid: 3x3 grid.
 * Return: True if the sandpile is stable, otherwise False.
 */

int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (false);
		}
	}
	return (true);
}

/**
 * stabilize_sandpile - Stabilize a sandpile.
 * @grid: Input sandpile.
 * @grid_tmp: 3x3 grid.
 * Return: Nothing.
 */

void stabilize_sandpile(int grid[3][3], int grid_tmp[3][3])
{
	while (!is_stable(grid))
	{
		int i, j;

		printf("=\n");
		print_sandpile(grid);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] > 3)
				{
					grid[i][j] -= 4;
					if (i > 0)
						grid_tmp[i - 1][j]++;
					if (i < 2)
						grid_tmp[i + 1][j]++;
					if (j > 0)
						grid_tmp[i][j - 1]++;
					if (j < 2)
						grid_tmp[i][j + 1]++;
				}
			}
		}
		sandpiles_sum(grid, grid_tmp);
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles into the first given.
 *
 * @grid1: Input sandpile.
 * @grid2: Input sandpile.
 *
 * Return: Nothing.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int grid_tmp[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid_tmp[i][j] = 0;
		}
	}
	stabilize_sandpile(grid1, grid_tmp);
}
