#include "menger.h"

/**
 * is_hole - Determines if a position should be a hole in the Menger sponge
 * @x: The x coordinate
 * @y: The y coordinate
 *
 * Return: 1 if the position is a hole, 0 otherwise
 */
int is_hole(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger sponge
 * @level: The level of the Menger Sponge to draw
 *
 * Description: Draws a 2D representation of a Menger sponge at the
 * specified level. If level is lower than 0, the function does nothing.
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
		return;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (is_hole(i, j))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
