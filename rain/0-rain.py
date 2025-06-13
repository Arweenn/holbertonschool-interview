#!/usr/bin/python3
"""
Rain water trapping algorithm module.
"""


def rain(walls):
    """
    Calculate the amount of rainwater that can be trapped.
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    total_water = 0

    for i in range(1, n - 1):
        left_max = 0
        for j in range(i):
            left_max = max(left_max, walls[j])

        right_max = 0
        for j in range(i + 1, n):
            right_max = max(right_max, walls[j])

        water_level = min(left_max, right_max)

        if water_level > walls[i]:
            total_water += water_level - walls[i]

    return total_water
