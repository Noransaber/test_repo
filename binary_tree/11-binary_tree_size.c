#include "binary_trees.h"
/**
* binary_tree_size -  measures the size of a binary tree
* @tree: pointer to the root
* Return: the size of the tree
**/
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t left_size, right_size, size;
if (tree == NULL)
return (0);



left_size = binary_tree_size(tree->left);
right_size = binary_tree_size(tree->right);
size = (left_size + 1 + right_size);

return (size);
}
