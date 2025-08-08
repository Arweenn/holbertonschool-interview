#!/usr/bin/python3
"""
Script that reads input and computes metrics.
"""

if __name__ == '__main__':

    import sys

    def print_results(statusCodes, fileSize):
        """
        Print results.
        """
        print(f"File size: {fileSize}")
        for statusCode, times in sorted(statusCodes.items()):
            if times:
                print(f"{statusCode}: {times}")

    statusCodes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }
    fileSize = 0
    n_lines = 0

    try:
        for line in sys.stdin:
            if n_lines != 0 and n_lines % 10 == 0:
                print_results(statusCodes, fileSize)
            n_lines += 1
            data = line.split()
            if len(data) >= 2:
                try:
                    statusCode = data[-2]
                    if statusCode in statusCodes:
                        statusCodes[statusCode] += 1
                    fileSize += int(data[-1])
                except (IndexError, ValueError):
                    continue

        print_results(statusCodes, fileSize)
    except KeyboardInterrupt:
        print_results(statusCodes, fileSize)
        raise
