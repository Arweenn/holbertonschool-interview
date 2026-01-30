#include <stdlib.h>
#include "binary_trees.h"


/**
* find_parent_node - locates the parent for the next insertion point
* @root: root node pointer of the binary heap structure
* @height: current depth level of the tree
* Return: parent node pointer for insertion
*/

heap_t *find_parent_node(heap_t *root, int height)
{
	heap_t *parent = root;

	if (root == NULL || height < 2)
		return (NULL);

	if (height == 2)
	{
		if (root->left == NULL || root->right == NULL)
			return (root);
		else
			return (NULL);
	}

	parent = find_parent_node(root->left, height - 1);
	if (parent == NULL)
		parent = find_parent_node(root->right, height - 1);

	return (parent);
}


/**
* swap_nodes - exchanges values between two heap nodes
* @node1: first node in the swap operation
* @node2: second node in the swap operation
*/

void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp;

	if (node1 == NULL || node2 == NULL)
		return;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}


/**
* height_tree - calculates the maximum depth of a binary tree
* @tree: root node pointer of the tree structure
* Return: total height measurement of the tree
*/

int height_tree(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = height_tree(tree->left);
	right_height = height_tree(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}


/**
* heap_insert - adds a new value to the Max Binary Heap structure
* @root: double pointer reference to the heap's root node
* @value: integer data to be stored in the new node
* Return: newly created node pointer, or NULL if operation fails
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;
	heap_t *move = *root;
	int height = height_tree(*root);

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
		return (*root = new_node);

	parent = find_parent_node(*root, height);
	if (parent == NULL)
	{
		while (move->left != NULL)
			move = move->left;
		parent = move;
	}

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		swap_nodes(new_node, new_node->parent);
		new_node = new_node->parent;
	}

	return (new_node);
}
