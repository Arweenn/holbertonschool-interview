# Rain Water Trapping Algorithm

## Description
This project implements a solution to the classic "trapping rainwater" problem. Given a list of non-negative integers representing the heights of walls, the algorithm calculates how many square units of water will be retained after it rains.

## Problem Statement
Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

## Algorithm
The solution uses a straightforward approach:
1. For each position (except the first and last), find the maximum wall height to its left and right
2. The water level at that position is the minimum of these two maximums
3. If the water level is higher than the current wall, water can be trapped
4. Sum up all the trapped water across all positions

## Files
- `0-rain.py`: Contains the main `rain()` function implementation
- `README.md`: This documentation file

## Usage
```python
#!/usr/bin/python3
rain = __import__('0-rain').rain

walls = [0, 1, 0, 2, 0, 3, 0, 4]
print(rain(walls))  # Output: 6

walls = [2, 0, 0, 4, 0, 0, 1, 0]
print(rain(walls))  # Output: 6
```

## Requirements
- Python 3.4.3 (Ubuntu 14.04 LTS)
- PEP 8 compliant code
- No external modules allowed
- All functions must be documented

## Time Complexity
O(n²) where n is the number of walls

## Space Complexity
O(1) - only using constant extra space
