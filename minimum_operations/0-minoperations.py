#!/usr/bin/python3
"""
Module for calculating minimum operations to reach n H characters
"""


def minOperations(n):
    """
    Calculate the fewest number of operations needed to result in exactly n H
    characters in the file.
    Args:
        n (int): Target number of H characters

    Returns:
        int: Minimum number of operations needed, or 0 if impossible
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while divisor * divisor <= n:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    if n > 1:
        operations += n

    return operations
