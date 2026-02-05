#include "sort.h"
#include <stdio.h>

void insertion_sort_list(listint_t **list)
{
    listint_t *tmp = (*list)->next;
    int n;
    listint_t *leading_header;
    int index = 1;

    while (tmp != NULL) 
    {
        n = index;
        leading_header = tmp;

        while (n)
        {
            if (tmp->n < tmp->prev->n)
            {
                if (n == index)
                    leading_header = tmp->prev;
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                tmp->prev->prev = tmp;
                tmp->next = tmp->prev;
                tmp->prev = NULL;
                print_list(*list);
            }

            n--;
        }

        tmp = leading_header->next;
        index++;
    }
}