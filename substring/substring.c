#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * hash_string - Simple hash function for strings
 * @str: String to hash
 * @len: Length of the string
 *
 * Return: Hash value
 */
static unsigned int hash_string(const char *str, int len)
{
	unsigned int hash = 5381;
	int i;

	for (i = 0; i < len; i++)
		hash = ((hash << 5) + hash) + str[i];

	return (hash);
}

/**
 * compare_strings - Compare two strings of given length
 * @s1: First string
 * @s2: Second string
 * @len: Length to compare
 *
 * Return: 1 if equal, 0 otherwise
 */
static int compare_strings(const char *s1, const char *s2, int len)
{
	int i;

	for (i = 0; i < len; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

/**
 * init_word_data - Initialize word hashes and counts
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 * @word_hashes: Array to store hashes
 * @word_count: Array to store counts
 */
static void init_word_data(char const **words, int nb_words, int word_len,
			   unsigned int *word_hashes, int *word_count)
{
	int i, j;

	for (i = 0; i < nb_words; i++)
	{
		word_hashes[i] = hash_string(words[i], word_len);
		for (j = 0; j <= i; j++)
			if (compare_strings(words[i], words[j], word_len))
				word_count[j]++;
	}
}

/**
 * match_words - Check if substring sequence matches word pattern
 * @s: Main string
 * @start: Starting position
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 * @word_hashes: Precomputed word hashes
 * @word_count: Word occurrence counts
 * @word_used: Temporary usage tracker
 *
 * Return: 1 if all words matched, 0 otherwise
 */
static int match_words(const char *s, int start, char const **words,
		       int nb_words, int word_len, unsigned int *word_hashes,
		       int *word_count, int *word_used)
{
	int j, k;
	const char *substr;
	unsigned int substr_hash;

	memset(word_used, 0, nb_words * sizeof(int));
	for (j = 0; j < nb_words; j++)
	{
		substr = s + start + j * word_len;
		substr_hash = hash_string(substr, word_len);
		for (k = 0; k < nb_words; k++)
		{
			if (substr_hash == word_hashes[k] &&
			    compare_strings(substr, words[k], word_len) &&
			    word_used[k] < word_count[k])
			{
				word_used[k]++;
				break;
			}
		}
		if (k == nb_words)
			return (0);
	}
	return (1);
}

/**
 * find_substring - Find all indices where word concatenations occur
 * @s: The string to scan
 * @words: Array of words to find
 * @nb_words: Number of words
 * @n: Pointer to store count of indices found
 *
 * Return: Array of indices or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, word_len, total_len, i, result_size = 0, result_cap = 10;
	int *result, *word_count, *word_used;
	unsigned int *word_hashes;

	*n = 0;
	if (!s || !words || nb_words == 0 || !words[0])
		return (NULL);
	s_len = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	if (total_len > s_len)
		return (NULL);
	result = malloc(result_cap * sizeof(int));
	word_count = calloc(nb_words, sizeof(int));
	word_used = calloc(nb_words, sizeof(int));
	word_hashes = malloc(nb_words * sizeof(unsigned int));
	if (!result || !word_count || !word_used || !word_hashes)
		return (free(result), free(word_count), free(word_used),
			free(word_hashes), NULL);
	init_word_data(words, nb_words, word_len, word_hashes, word_count);
	for (i = 0; i <= s_len - total_len; i++)
	{
		if (!match_words(s, i, words, nb_words, word_len,
				word_hashes, word_count, word_used))
			continue;
		if (result_size >= result_cap)
		{
			result_cap *= 2;
			result = realloc(result, result_cap * sizeof(int));
			if (!result)
				break;
		}
		result[result_size++] = i;
	}
	free(word_count), free(word_used), free(word_hashes);
	*n = result_size;
	return (result_size == 0 ? (free(result), NULL) :
		realloc(result, result_size * sizeof(int)));
}
