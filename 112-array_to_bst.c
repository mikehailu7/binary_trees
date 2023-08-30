#include "binary_trees.h"
/**
 * array_to_bst - function used to build atree
 * @array: used to store the array
 * Author: Mikias Hailu and Yared Tsgie
 * @size: used to store the size of the array
 * Return: success
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t x, y;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (bst_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
