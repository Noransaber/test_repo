#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/** -------------------------------------------------------------- */

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;

/** -------------------------------------------------------------- */

/** FUNCTION PROTOTYPES */
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
int binary_tree_balance(const binary_tree_t *tree);

int binary_tree_is_perfect(const binary_tree_t *tree);
int tree_height(const binary_tree_t *tree);
size_t tree_size(const binary_tree_t *tree);
size_t custom_pow(size_t base, size_t exponent);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second);
int depth(const binary_tree_t *tree);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void o_level(const binary_tree_t *tree, void (*func)(int), size_t step);
size_t t_height(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);
int bal_avl(const binary_tree_t *tree, int lower, int high);
size_t binary_tree_height(const binary_tree_t *tree);
int bal_avl(const binary_tree_t *tree, int lower, int heigh);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *a_sort(avl_t *parent, int *array, int b, int l);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);

#endif /* _BINARY_TREES_H_ */
