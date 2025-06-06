#!/usr/bin/python3
"""
Module for solving the lockboxes problem.
"""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be opened.
    Args:
        boxes (list): A list of lists where each inner list contains
                     keys (integers) that can open other boxes.
    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    if not boxes or len(boxes) == 0:
        return True

    n = len(boxes)
    opened = set([0])
    keys = set(boxes[0])

    keys = {key for key in keys if key < n}

    while True:
        new_boxes_opened = False

        for key in list(keys):
            if key not in opened and key < n:
                opened.add(key)
                for new_key in boxes[key]:
                    if new_key < n:
                        keys.add(new_key)
                new_boxes_opened = True

        if not new_boxes_opened:
            break

    return len(opened) == n
