#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: Root node
 * Return: o if NULL
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (1);
}
    
if ((tree->left) && (tree->right))
{
// Recurse into left and right subtrees
return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
else if ((tree->left == NULL) && (tree->right == NULL))
{
// Leaf node (no children) in a full binary tree
return (1);
}
    
return (0); // If only one child is present, it's not a full binary tree
}

