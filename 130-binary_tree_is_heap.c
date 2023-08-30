#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * binary_tree_is_heap - function used to check  binary tree is heap
 * @tree: used to store the tree
 * Return: 1 success 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
        int t;

        if (!tree)
                return (0);

        tmp = binary_tree_is_complete(tree);
        if (!t)
                return (0);
        return (check_max(tree));
}

/**
 * check_max - function used to check whether max or not
 * @tree: used to store the tree
 * Return: 1 success 0 failer
 **/
int check_max(const binary_tree_t *tree)
{
	int t1 = 1, t2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		t1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		t2 = check_max(tree->right);
	}
	return (t1 && t2);
}
