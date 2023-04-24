#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using the Cocktail shaker sort algorithm
 *
 * @list: Double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current, *tail;

    if (list == NULL || *list == NULL)
        return;

    tail = *list;
    while (tail->next != NULL)
        tail = tail->next;

    while (swapped == 1)
    {
        swapped = 0;
        current = *list;

        while (current != NULL && current != tail)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            }
            else
                current = current->next;
        }

        if (swapped == 0)
            break;

        swapped = 0;
        tail = tail->prev;
        current = tail;

        while (current != NULL && current != (*list)->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list);
            }
            else
                current = current->prev;
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Double pointer to the head of the linked list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *prev1, *next1, *prev2, *next2;

    if (node1 == NULL || node2 == NULL || list == NULL || *list == NULL)
        return;

    prev1 = node1->prev;
    next1 = node1->next;
    prev2 = node2->prev;
    next2 = node2->next;

    if (prev1 != NULL)
        prev1->next = node2;

    if (next2 != NULL)
        next2->prev = node1;

    node1->prev = prev2;
    node1->next = next2;
    node2->prev = prev1;
    node2->next = next1;

    if (prev1 == NULL)
        *list = node2;

    if (next2 == NULL)
        *list = node1;
}

listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
