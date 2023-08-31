#include "binary_trees.h"
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of
 * array to be converted
 * @size:number of element in the array
 * Return:  pointer to the root node of the created AVL tree
 * or NULL on failure
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
if (array == NULL || size == 0)
{
return (NULL);
}

return (a_sort(NULL, array, 0, ((int)(size)) - 1));
}
/**
 * a_sort - create a tree using half of the array elements
 * @parent: root
 * @array: sorted array
 * @b: start
 * @l: last position
 * Return: created tree
 **/
avl_t *a_sort(avl_t *parent, int *array, int b, int l)
{
avl_t *root;
binary_tree_t *a;
int m = 0;

if (b <= l)
{
m = (b + l) / 2;
a = binary_tree_node((binary_tree_t *)parent, array[m]);
if (a == NULL)
{
return (NULL);
}

root = (avl_t *)a;
root->left = a_sort(root, array, b, m - 1);
root->right = a_sort(root, array, m + 1, l);
return (root);
}
return (NULL);
}
