# Wild Compare

This project implements a wildcard string comparison function that can match strings with the special `*` character.

## Function

### `wildcmp`
- **Prototype:** `int wildcmp(char *s1, char *s2);`
- **Description:** Compares two strings and returns 1 if they can be considered identical, otherwise returns 0
- **Special Character:** The `*` in `s2` can replace any string (including an empty string)

## Algorithm

The function uses recursion to handle the wildcard matching:

1. **Base case:** If `s2` reaches the end (`\0`), check if `s1` also reached the end
2. **Wildcard handling:** When encountering `*` in `s2`:
   - Skip consecutive asterisks
   - If `*` is at the end, it matches everything remaining
   - Try matching `*` with empty string (advance `s2`)
   - Try matching `*` with current character and continue (advance `s1`)
3. **Character matching:** If current characters are the same, recursively check the rest
4. **No match:** If characters don't match and no wildcard, return 0

## Examples

```c
wildcmp("main.c", "*.c");           // Returns 1
wildcmp("main.c", "m*a*i*n*.*c*");  // Returns 1
wildcmp("main.c", "main.c");        // Returns 1
wildcmp("main.c", "m*c");           // Returns 1
wildcmp("main.c", "*");             // Returns 1
wildcmp("main.c", "m.*c");          // Returns 0 (. doesn't match i)
```

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o wildcmp
```

## Files

- `0-wildcmp.c`: Main implementation file
- `holberton.h`: Header file with function prototype
- `README.md`: This documentation file