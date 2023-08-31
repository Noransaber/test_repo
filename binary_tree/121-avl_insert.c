#include "binary_trees.h"
/**
* avl_insert - new value insertion.
* @tree: pointer to the root.
* @value: value to be inserted
* Return: inserted node, or NULL if fails.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *new = NULL;

if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}
r_insert_node(tree, *tree, &new, value);
return (new);
}

#include "binary_trees.h"

/**
* r_insert_node - insertions method
* @tree: root.
* @parent: parent node.
* @new: pointer to new value.
* @nval: value.
* Return: pointer to inserted node
*/
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
int bval;

if (*tree == NULL)
return (*new = binary_tree_node(parent, nval));
if ((*tree)->n > nval)
{
(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, nval);
if ((*tree)->left == NULL)
return (NULL);
}
else if ((*tree)->n < nval)
{
(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, nval);
if ((*tree)->right == NULL)
return (NULL);
}
else
{
return (*tree);
}
bval = binary_tree_balance(*tree);
if (bval > 1 && (*tree)->left->n > nval)
{
*tree = binary_tree_rotate_right(*tree);
}
else if (bval > 1 && (*tree)->left->n < nval)
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
*tree = binary_tree_rotate_right(*tree);
}
else if (bval < -1 && (*tree)->right->n < nval)
{
*tree = binary_tree_rotate_left(*tree);
}
else if (bval < -1 && (*tree)->right->n > nval)
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
*tree = binary_tree_rotate_left(*tree);
}
return (*tree);
}
