# Making Change

This project implements a dynamic programming solution to the classic coin change problem.

## Problem Description

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount `total`.

## Function

### `makeChange(coins, total)`

**Parameters:**
- `coins`: A list of the values of the coins in your possession (integers > 0)
- `total`: The target amount to make change for

**Returns:**
- Fewest number of coins needed to meet `total`
- `0` if `total` is `0` or less
- `-1` if `total` cannot be met by any number of coins you have

**Assumptions:**
- You have an infinite number of each denomination of coin in the list
- The value of a coin will always be an integer greater than 0

## Algorithm

The solution uses dynamic programming with a bottom-up approach:

1. Create a DP array where `dp[i]` represents the minimum number of coins needed to make amount `i`
2. Initialize all values to infinity except `dp[0] = 0` (base case)
3. For each amount from 1 to `total`, try each coin denomination
4. Update the minimum coins needed using the recurrence relation:
   `dp[amount] = min(dp[amount], dp[amount - coin] + 1)`

## Time Complexity

- **Time Complexity:** O(total × len(coins))
- **Space Complexity:** O(total)

## Usage

```python
makeChange = __import__('0-making_change').makeChange

# Example 1: coins=[1, 2, 25], total=37
# Result: 7 coins (25 + 2*2 + 2*1 + 2*1 + 2*1 + 2*1 + 2*1)
print(makeChange([1, 2, 25], 37))  # Output: 7

# Example 2: coins=[1256, 54, 48, 16, 102], total=1453
# Result: -1 (impossible to make exact change)
print(makeChange([1256, 54, 48, 16, 102], 1453))  # Output: -1
```

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 style compliance
- Files must be executable and end with a new line
- First line must be `#!/usr/bin/python3`
