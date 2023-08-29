#include "binary_trees.h"
#include "limits.h"
/**
 * binary_tree_is_bst - function used to check the tree is best
 * @tree: used to store the tree
 * Return: 1 suceess and 0 failure
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);
        return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
/**
 * is_bst_helper - function used to ckeck the tree is best
 * @tree: used tos tore the tree
 * @lo: used to store the lowest value
 * @hi: used to store the highest
 * Return: 1 success and 0 failer
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

