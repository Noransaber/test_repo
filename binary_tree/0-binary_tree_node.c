#include <stdlib.h>
#include "binary_trees.h"
/**
* binary_tree_node - creates a binary tree node
* @parent: The root node
* @value: The data
* Return: pointer to the new node
**/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *newNode = malloc(sizeof(binary_tree_t));
if (newNode == NULL)
return NULL;

newNode->left = NULL;
newNode->right = NULL;
newNode->n = value;
newNode->parent = parent;
return (newNode);
}
