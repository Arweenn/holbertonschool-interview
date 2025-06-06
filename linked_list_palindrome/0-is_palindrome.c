#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to the head of the list
 * Return: pointer to the new head of the reversed list
 */
static listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *current = head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return (prev);
}



/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second_half, *prev_slow;
	listint_t *midnode = NULL;
	int result = 1;

	if (head == NULL || *head == NULL)
		return (1);

	if ((*head)->next == NULL)
		return (1);

	slow = fast = *head;
	prev_slow = NULL;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	if (fast != NULL)
	{
		midnode = slow;
		slow = slow->next;
	}

	if (prev_slow != NULL)
		prev_slow->next = NULL;

	second_half = reverse_list(slow);

	result = 1;
	listint_t *first_half = *head;

	while (second_half != NULL && first_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			result = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	second_half = reverse_list(second_half);

	if (midnode != NULL)
	{
		if (prev_slow != NULL)
			prev_slow->next = midnode;
		midnode->next = second_half;
	}
	else
	{
		if (prev_slow != NULL)
			prev_slow->next = second_half;
	}

	return (result);
}
