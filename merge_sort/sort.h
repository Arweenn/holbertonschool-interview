
#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);

#endif /* _SORT_H_ */
