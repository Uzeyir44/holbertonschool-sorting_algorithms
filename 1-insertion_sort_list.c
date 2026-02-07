#include "sort.h"
#include <stdio.h>

void insertion_sort_list(listint_t **list)
{
    listint_t *tmp = (*list)->next;
    int n;
    listint_t *leading_header;
    int index = 1;
    listint_t *right;
    listint_t *left;

    while (tmp != NULL) 
    {
        n = index;
        leading_header = tmp;

        while (n)
        {
            if (tmp->n < tmp->prev->n)
            {
                left = tmp->prev;
                right = tmp->next;

                if (n == index)
                    leading_header = tmp->prev;

                left->next = tmp->next;
                right->prev = tmp->prev;
                tmp->prev = left->prev;
                tmp->next = left;
                if (tmp->prev == NULL)
                    *list = tmp;

                print_list(*list);
            }

            n--;
        }

        tmp = leading_header->next;
        index++;
    }
}