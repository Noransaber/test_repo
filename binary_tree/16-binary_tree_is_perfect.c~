#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: Pointer to the root of the tree
 * Return: 1 if perfect OTHERWISE 0
 **/
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t height, i;

if (tree == NULL)
{
return (0);
}

height = binary_tree_height(tree);

for (i = 0; i < height; i++)
{
if ((1 << i) + i - 1 >= height)
return (0);
}

return (1);
}
