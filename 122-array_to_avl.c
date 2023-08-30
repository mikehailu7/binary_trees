#include "binary_trees.h"
/**
 * array_to_avl: This funciton will Builds an AVL tree from an array
 * @array: This is a pointer that points to the first element of the array to be converted
 * @size: This shows the number of elements in @array
 * Author: Mikias Hailu and Yared Tsgie
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t m, n;
	if (array == NULL)
		return (NULL);

	for (m = 0; m < size; m++)
	{
		for (n = 0; n < m; n++)
		{
			if (array[n] == array[m])
				break;
		}
		if (n == m)
		{
			if (avl_insert(&tree, array[m]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
