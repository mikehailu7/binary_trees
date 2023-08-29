#include "binary_trees.h"
/**
 * binary_trees_ancestor: This funciton will finds the lowest common ancestor of two nodes
 * @first: This represent the first node
 * @second: This represent the second node
 * Return: This will return the lowest common ancestor
 * Author: Mikias Hailu and Yared Tsgie
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t hgt_m = 0, hgt_n = 0;
	const binary_tree_t *aux = NULL;
	hgt_m = binary_tree_depth(first);
	hgt_n = binary_tree_depth(second);
	if (hgt_m && hgt_n)
	{
		if (hgt_m > hgt_n)
		{
			aux = first;
			first = second;
			second = aux;
		}
		while (first)
		{
			aux = second;
			while (aux)
			{
				if (first == aux)
					return ((binary_tree_t *)first);
				aux = aux->parent;
			}
			first = first->parent;
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}
/**
 * binary_tree_depth: This funciton will measures the depth of a node in a binary tree.
 * @tree: This pointer will point to the node to measure the depth.
 * Author: Mikias Hailu and Yared Tsgie
 * Return: This will return if tree is NULL, function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
