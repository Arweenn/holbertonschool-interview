#!/usr/bin/python3
"""Log parsing script that computes metrics from stdin"""

import sys
import signal
import re


def print_stats(total_size, status_counts):
    """Print the current statistics"""
    print("File size: {}".format(total_size))
    for status_code in sorted(status_counts.keys()):
        if status_counts[status_code] > 0:
            print("{}: {}".format(status_code, status_counts[status_code]))


def signal_handler(sig, frame):
    """Handle keyboard interrupt (CTRL+C)"""
    global total_size, status_counts
    print_stats(total_size, status_counts)
    sys.exit(0)


if __name__ == "__main__":
    total_size = 0
    status_counts = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0
    }
    line_count = 0

    signal.signal(signal.SIGINT, signal_handler)

    ip_and_date_pattern = r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - \[.*\] '
    request_pattern = r'"GET /projects/260 HTTP/1\.1" (\d+) (\d+)'
    log_pattern = re.compile(ip_and_date_pattern + request_pattern)

    try:
        for line in sys.stdin:
            line = line.strip()
            match = log_pattern.match(line)

            if match:
                ip_address, status_code_str, file_size_str = match.groups()

                try:
                    status_code = int(status_code_str)
                    file_size = int(file_size_str)

                    total_size += file_size

                    if status_code in status_counts:
                        status_counts[status_code] += 1

                    line_count += 1

                    if line_count % 10 == 0:
                        print_stats(total_size, status_counts)

                except ValueError:
                    continue

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)

    print_stats(total_size, status_counts)