# Minimum Operations

This project contains a solution to calculate the minimum number of operations needed to achieve exactly `n` 'H' characters in a text file, starting with a single 'H' character.

## Problem Description

Given a text file containing a single character 'H', you can perform only two operations:
- **Copy All**: Copies all characters currently in the file
- **Paste**: Pastes the previously copied characters

The goal is to find the minimum number of operations to get exactly `n` 'H' characters.

## Algorithm

The solution uses the mathematical insight that this problem is equivalent to finding the sum of all prime factors of `n`. 

For any number `n`, the optimal strategy is:
1. Find all prime factors of `n`
2. Sum these prime factors
3. This sum represents the minimum operations needed

### Example
- For `n = 9 = 3 × 3`: Operations = 3 + 3 = 6
- For `n = 12 = 2² × 3`: Operations = 2 + 2 + 3 = 7

## Files

- `0-minoperations.py`: Contains the `minOperations` function
- `README.md`: This documentation file

## Usage

```python
#!/usr/bin/python3
minOperations = __import__('0-minoperations').minOperations

n = 9
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
# Output: Min # of operations to reach 9 char: 6
```

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 compliant code
- Executable files with proper shebang
