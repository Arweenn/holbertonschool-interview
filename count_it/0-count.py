#!/usr/bin/python3
import re
import requests
"""
    Recursively queries the Reddit API and counts occurrences of keywords
    in hot post titles.
"""


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively queries the Reddit API and counts occurrences of keywords
    in hot post titles.
    """
    if counts is None:
        counts = {}
        for word in word_list:
            word_lower = word.lower()
            if word_lower not in counts:
                counts[word_lower] = 0
            else:
                counts[word_lower] += 0

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "linux:0:1.0 (by /u/my_username)"}
    params = {"limit": 100}

    if after:
        params["after"] = after

    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json()
    posts = data["data"]["children"]

    for post in posts:
        title = post["data"]["title"].lower()
        for word in word_list:
            word_lower = word.lower()
            matches = re.findall(r'\b' + re.escape(word_lower) + r'\b', title)
            counts[word_lower] += len(matches)

    after = data["data"]["after"]
    if after:

        return count_words(subreddit, word_list, after, counts)
    else:
        filtered_counts = {k: v for k, v in counts.items() if v > 0}

        sorted_words = sorted(filtered_counts.items(),
                              key=lambda x: (-x[1], x[0]))

        for word, count in sorted_words:
            print(f"{word}: {count}")
