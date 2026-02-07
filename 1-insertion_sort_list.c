#include "sort.h"
#include <stdio.h>

void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *next, *left, *right;

    curr = (*list)->next;

    while(curr != NULL)
    {
        next = curr->next;

        while(curr->prev != NULL && curr->n < curr->prev->n)
        {
            left = curr->prev;
            right = curr->next;

            left->next = curr->next;
            if (right != NULL)
                right->prev = left;

            curr->next = left;
            curr->prev = left->prev;
            
            if (left->prev != NULL)
                left->prev->next = curr;
            else
                *list = curr;

            left->prev = curr;

            print_list(*list);
        }

        curr = next;
    }
}