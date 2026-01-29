#ifndef SUBSTRING_H
#define SUBSTRING_H

/**
 * find_substring - Finds all starting indices of substrings in s that are
 *                  concatenations of all words in the words array
 * @s: The string to scan
 * @words: Array of words to find (all same length)
 * @nb_words: Number of words in the words array
 * @n: Pointer to store the number of indices found
 *
 * Return: Array of indices or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
