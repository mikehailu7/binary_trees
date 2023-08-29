#include "binary_trees.h"
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_height: This funciton will measures the height of a binary tree
 * @tree: This pointer will point to the root node of the tree to measure the height
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}
/**
 * binary_tree_levelorder: This funcitown will go through a binary tree in level-order traversal
 * @func: This pointer will point to a function to call for each node
 * @tree: This pointer will point to the root node of the tree to traverse
 * Author: Mikias Hailu and Yared Tsgie
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t m = 0, e = 1;

	if (tree && func)
	{
		m = binary_tree_height(tree);
		while (e <= m + 1)
		{
			print_at_level(tree, func, e);
			e++;
		}
	}
}
/**
 * print_at_level - print node, especific level
 * @tree: pointer to the root node of the tree to traverse
 * @level: level to print
 * @func: pointer to a function to call for each node
 * Author: Mikias Hailu and Yared tsgie
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}
}
