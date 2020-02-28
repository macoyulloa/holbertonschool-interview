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

static int check_sandpiles(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return 1;
	return 0;
}

void converting_into_sandpiles(int grid1[3][3], int grid_count[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
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
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 * Return: void function
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, checker;
	int grid_count[3][3];

	sum_two_grid(grid1, grid2);
	print_grid(grid1);

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid_count[i][j] = 0;

	checker = check_sandpiles(grid1);
	if (checker == 1)
	{
		print_grid(grid_count);
		converting_into_sandpiles(grid1, grid_count);
		print_grid(grid1);
		print_grid(grid_count);
		sum_two_grid(grid1, grid_count);
		print_grid(grid1);
	}
}
