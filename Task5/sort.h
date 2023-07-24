#ifndef SORT_H
#define SORT_H

/** LIBRARU FILES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**DATA STRUCTURE FOR DOUBLY LINKED LIST*/
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
        const int n;
        struct listint_s *prev;
        struct listint_s *next;
} listint_t;

/**FUNCTION PROTOTYPES*/
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void linklist_swapping(listint_t *sec, listint_t *first, listint_t **h);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
int partition(int *array, int first, int last, size_t size);
void quicksort_recursion(int *array, int first, int last, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_sh(int *arr, int x, int y, int *swapped);
void merge(size_t l, size_t m, size_t r, int *dest, int *org);
void merge_recrusion(size_t l, size_t r, int *a, int *cpy_arr);
void merge_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
size_t partition_h(int *a, size_t first, size_t last, size_t size);
void quicksort_recursion_h(int *array, int first, int last, size_t size);
void quick_sort_hoare(int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void move_left(listint_t *sec, listint_t *first, listint_t **h);
#endif
