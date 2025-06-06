# Lockboxes

This project contains a solution to the lockboxes problem, which determines if all boxes in a collection can be opened given that each box may contain keys to other boxes.

## Problem Description

You have `n` number of locked boxes in front of you. Each box is numbered sequentially from `0` to `n - 1` and each box may contain keys to the other boxes.

### Requirements

- Write a method that determines if all the boxes can be opened
- Prototype: `def canUnlockAll(boxes)`
- `boxes` is a list of lists
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- There can be keys that do not have boxes
- The first box `boxes[0]` is unlocked
- Return `True` if all boxes can be opened, else return `False`

## Files

- `0-lockboxes.py`: Contains the `canUnlockAll` function that solves the problem
- `README.md`: This file

## Algorithm

The solution uses a breadth-first search approach:

1. Start with box 0 (always unlocked)
2. Keep track of opened boxes and available keys
3. For each opened box, collect all keys inside
4. Use keys to open new boxes
5. Continue until no more boxes can be opened
6. Return True if all boxes are opened

## Usage

```python
#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))  # False
```

## Compatibility

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 compliant
