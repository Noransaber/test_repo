#include "binary_trees.h"
/**
 * binary_tree_nodes -  counts the nodes with at
 * least 1 child in a binary tree
 * @tree: The root node
 * Return: 0 if null, the count of the nodes
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t rightN, leftN;

if (tree == NULL)
{
return (0);
}
rightN = binary_tree_nodes(tree->right);
leftN = binary_tree_nodes(tree->left);

if (tree->left || tree->right)
{
return (1 + leftN + rightN);
}
else
{
return (leftN + rightN);
}
}

