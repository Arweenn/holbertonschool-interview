#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_array_range - Prints a range of elements from an array
 * @array: Array to print from
 * @start: Starting index
 * @end: Ending index
 * @separator: Text to print between elements (or NULL for none)
 */
void print_array_range(int *array, size_t start, size_t end, char *separator)
{
	size_t i;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end && separator)
			printf("%s", separator);
	}
	printf("\n");
}

/**
 * merge - Merges two subarrays into one sorted array
 * @array: Original array containing subarrays to merge
 * @temp: Temporary array to store the merged result
 * @left: Start index of left subarray
 * @mid: End index of left subarray / start of right subarray - 1
 * @right: End index of right subarray
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array_range(array, left, mid, ", ");
	printf("[right]: ");
	print_array_range(array, mid + 1, right, ", ");

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array_range(array, left, right, ", ");
}

/**
 * merge_sort_recursive - Recursively sorts an array using merge sort algorithm
 * @array: Array to be sorted
 * @temp: Temporary array for merging
 * @left: Start index of the array
 * @right: End index of the array
 *
 * Description: Implements top-down merge sort where left subarray <= right
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (left >= right)
		return;

	if ((right - left) % 2 == 0)
		mid = left + (right - left) / 2 - 1;
	else
		mid = left + (right - left) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid + 1, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}
