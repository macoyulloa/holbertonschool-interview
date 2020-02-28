#include "sandpiles.h"


static void sum_two_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

static void print_grid(int grid[3][3])
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

static int check_sandpiles(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				printf("not is a sandpile");
				return 0;
		}
	}
	printf("is a sandpile");
	return 1;
}

/**
 *
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid: sandpiles stable
 * @grid: sandpiles stable
 * Return: void function
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int grid_count[3][3];

	sum_two_grid(grid1, grid2);
	print_grid(grid1);

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid_count[i][j] = 0;

	while (check_sandpiles(grid1) == 0)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if (i > 0)
						grid_count[i-1][j] = grid_count[i-1][j] + 1;
					if (j > 0)
						grid_count[i][j-1] = grid_count[i][j-1] + 1;
					if (i < 2)
						grid_count[i+1][j] = grid_count[i+1][j] + 1;
					if (j < 2)
						grid_count[i][j+1] = grid_count[i+1][j] + 1;
				}
			}
		}
		sum_two_grid(grid1, grid_count);
		print_grid(grid1);
	}
	print_grid(grid_count);
}
