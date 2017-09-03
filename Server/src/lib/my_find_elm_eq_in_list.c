/*
** my_find_elm_eq_in_list.c for my_find_elm_eq_in_list in /home/bongol_b/rendu/Piscine_C_J11/ex_06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 16:16:14 2015 berdrigue bongolo-beto
** Last update Wed May 31 16:43:33 2017 bongol_b
*/

#include <stdlib.h>
#include "mylist.h"

void		*my_find_elm_eq_in_list(t_list *begin, void *data_ref,
					int (*cmp)())
{
  t_list	*current;

  current = begin;
  while (current != NULL)
    {
      if ((*cmp)(current->data, data_ref) == 0)
	{
	  return (current->data);
	}
      current = current->next;
    }
  return (NULL);
}
