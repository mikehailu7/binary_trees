#include "binary_trees.h"
/**
 * binary_tree_delete - THis function used to delete the entire tree
 * @tree: pointer used to point the deleted tree
 * Author: Mikias Hailu and yared tsgie
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
