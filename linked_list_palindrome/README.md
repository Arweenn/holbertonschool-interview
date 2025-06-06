# Palindrome Linked List

A C implementation to check if a singly linked list is a palindrome.

## 📋 Problem Description

Write a function that checks if a singly linked list is a palindrome. A palindrome reads the same forwards and backwards.

**Function Prototype:**
```c
int is_palindrome(listint_t **head);
```

**Requirements:**
- Return `1` if the list is a palindrome, `0` otherwise
- An empty list is considered a palindrome
- Must follow Betty coding style
- No global variables allowed
- Maximum 5 functions per file

## 🚀 Algorithm Overview

The solution uses an efficient **two-pointer approach** with **in-place reversal**:

1. **Find Middle**: Use slow/fast pointers to locate the middle of the list
2. **Split**: Divide the list into two halves
3. **Reverse**: Reverse the second half of the list
4. **Compare**: Compare elements from both halves
5. **Restore**: Reverse back and reconnect to preserve original structure

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

## 📁 File Structure

```
├── 0-is_palindrome.c    # Main implementation
├── lists.h             # Header file with struct definitions
├── linked_lists.c      # Helper functions (print, add, free)
├── 0-main.c           # Test file
└── README.md          # This file
```

## 🏗️ Data Structure

```c
typedef struct listint_s
{
    int n;                    /* Integer value */
    struct listint_s *next;   /* Pointer to next node */
} listint_t;
```

## 💻 Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

## 🧪 Usage Example

```c
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;
    
    /* Create palindrome: 1 -> 2 -> 3 -> 2 -> 1 */
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 1);
    
    if (is_palindrome(&head) == 1)
        printf("Linked list is a palindrome\n");
    else
        printf("Linked list is not a palindrome\n");
    
    free_listint(head);
    return (0);
}
```

## 📊 Test Cases

| Input List | Expected Output | Reason |
|------------|----------------|---------|
| `[]` (empty) | `1` (palindrome) | Empty list is palindrome |
| `[1]` | `1` (palindrome) | Single element |
| `[1,2,1]` | `1` (palindrome) | Odd-length palindrome |
| `[1,2,2,1]` | `1` (palindrome) | Even-length palindrome |
| `[1,2,3]` | `0` (not palindrome) | Not symmetric |

## ✨ Key Features

- **Non-destructive**: Preserves original list structure
- **Memory efficient**: Uses constant extra space
- **Edge case handling**: Properly handles empty and single-node lists
- **Betty compliant**: Follows required coding standards
- **Robust**: Works with both odd and even length lists

## 🔧 Algorithm Walkthrough

For list `[1, 2, 3, 2, 1]`:

1. **Find middle**: slow pointer stops at `3`
2. **Split**: `[1, 2]` and `[2, 1]` (skip middle `3`)
3. **Reverse second**: `[1, 2]` and `[1, 2]`
4. **Compare**: `1==1 ✓`, `2==2 ✓` → Palindrome!
5. **Restore**: Reconnect to original `[1, 2, 3, 2, 1]`

## 🎯 Technical Interview Notes

This problem tests:
- **Linked list manipulation**
- **Two-pointer technique**
- **In-place algorithms**
- **Edge case handling**
- **Memory management**

Common follow-up questions:
- Can you do it without modifying the list?
- What about using recursion?
- How would you handle very large lists?

## 📝 System Requirements

- **OS**: Ubuntu 14.04 LTS
- **Compiler**: gcc 4.8.4
- **Flags**: `-Wall -Werror -Wextra -pedantic`
- **Style**: Betty coding standard

## 🤝 Contributing

This is a technical interview preparation exercise. Focus on:
- Clean, readable code
- Proper error handling
- Comprehensive testing
- Documentation

---

*This implementation prioritizes efficiency and code clarity while maintaining the original list structure.*