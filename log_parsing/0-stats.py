#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics from log entries.
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
"""

import sys
import re
import signal


def print_stats(total_size, status_counts):
    """Print current statistics"""
    print("File size: {}".format(total_size))

    valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]
    for code in sorted(valid_codes):
        if code in status_counts and status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


def signal_handler(signum, frame):
    """Handle keyboard interruption (CTRL+C)"""
    print_stats(total_size, status_counts)
    sys.exit(0)


def parse_log_line(line):
    """
    Parse a log line and extract status code and file size.
    Returns (status_code, file_size) tuple or (None, None) if invalid format.
    """
    pattern = r'^(\S+) - \[([^\]]+)\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'

    match = re.match(pattern, line.strip())
    if match:
        try:
            status_code = int(match.group(3))
            file_size = int(match.group(4))
            return status_code, file_size
        except ValueError:
            return None, None

    return None, None


if __name__ == "__main__":
    total_size = 0
    status_counts = {}
    line_count = 0
    valid_status_codes = [200, 301, 400, 401, 403, 404, 405, 500]

    signal.signal(signal.SIGINT, signal_handler)

    try:
        for line in sys.stdin:
            status_code, file_size = parse_log_line(line)

            if status_code is None or file_size is None:
                continue

            if status_code in valid_status_codes:
                total_size += file_size
                status_counts[status_code] = status_counts.get(status_code, 0) + 1
                line_count += 1

                if line_count % 10 == 0:
                    print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
    except Exception:
        print_stats(total_size, status_counts)