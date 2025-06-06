# Island Perimeter

This project contains a solution to calculate the perimeter of an island represented in a 2D grid.

## Description

The `island_perimeter` function calculates the perimeter of an island described in a grid where:
- 0 represents water
- 1 represents land
- Each cell is a square with side length of 1
- Cells are connected horizontally/vertically (not diagonally)
- The grid is completely surrounded by water
- There is only one island (or nothing)
- The island doesn't have "lakes"

## Files

- `0-island_perimeter.py`: Contains the main function that calculates island perimeter
- `0-main.py`: Test file to demonstrate the function usage

## Usage

```python
#!/usr/bin/python3
island_perimeter = __import__('0-island_perimeter').island_perimeter

grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
print(island_perimeter(grid))  # Output: 12
```

## Algorithm

The function works by:
1. Iterating through each cell in the grid
2. For each land cell (value 1), checking all four adjacent directions
3. Adding 1 to the perimeter for each direction that is either water or outside the grid boundary
4. Returning the total perimeter count

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 compliant code
- No external modules imported
