# UTF-8 Validation

This project contains a Python implementation to validate UTF-8 encoding.

## Description

UTF-8 is a variable-width character encoding that can represent every character in the Unicode character set. Characters can be 1 to 4 bytes long.

### UTF-8 Encoding Rules:
- **1-byte characters**: `0xxxxxxx` (0-127)
- **2-byte characters**: `110xxxxx 10xxxxxx` (128-2047)  
- **3-byte characters**: `1110xxxx 10xxxxxx 10xxxxxx` (2048-65535)
- **4-byte characters**: `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx` (65536-1114111)

## Files

- `0-validate_utf8.py`: Contains the `validUTF8()` function that validates UTF-8 encoding
- `0-main.py`: Test file to demonstrate the function

## Function

### `validUTF8(data)`

**Parameters:**
- `data`: List of integers representing bytes

**Returns:**
- `True` if data represents valid UTF-8 encoding
- `False` otherwise

**Example:**
```python
validUTF8([65])  # Returns True (single ASCII character 'A')
validUTF8([229, 65, 127, 256])  # Returns False (invalid UTF-8 sequence)
```

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 style compliance
- All files must be executable
- All files must end with a new line

## Usage

```bash
./0-main.py
```
