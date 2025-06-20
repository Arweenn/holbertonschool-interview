# Radix Sort

This project implements the Radix Sort algorithm using the LSD (Least Significant Digit) approach in C.

## Description

The Radix Sort algorithm is a non-comparative sorting algorithm that sorts integers by processing individual digits. The LSD radix sort processes digits from the least significant digit to the most significant digit.

## Files

- `sort.h`: Header file containing function prototypes
- `0-radix_sort.c`: Implementation of the radix sort algorithm
- `print_array.c`: Function to print arrays (provided)

## Algorithm

1. Find the maximum number to know the number of digits
2. For each digit position (starting from the least significant):
   - Use counting sort to sort elements based on current digit
   - Print the array after each iteration

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

## Usage

The function `radix_sort` sorts an array of integers in ascending order:

```c
void radix_sort(int *array, size_t size);
```

- `array`: Pointer to the array to be sorted
- `size`: Number of elements in the array

## Time Complexity

- Best Case: O(d * (n + k)) where d is the number of digits, n is the number of elements, and k is the range of input
- Average Case: O(d * (n + k))
- Worst Case: O(d * (n + k))

## Space Complexity

O(n + k) for the auxiliary arrays used in counting sort

## Assumptions

- The array contains only non-negative integers (>= 0)
- The array size is at least 2 for sorting to occur
