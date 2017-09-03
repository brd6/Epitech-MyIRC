/*
** my_rm_el_from_list.c for my_rm_el_from_list in /home/bongol_b/rendu/Piscine_C_J11
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jan 14 23:59:08 2016 Berdrigue BONGOLO BETO
** Last update Sat Jun  3 11:28:28 2017 bongol_b
*/

#include <stdlib.h>
#include "mylist.h"
#include "myirc.h"

int		my_rm_el_from_list(t_list **begin,
				   void *data_ref,
				   int (*cmp)())
{
  t_list	*curr;
  t_list	*prev;

  prev = NULL;
  curr = *begin;
  while (curr != NULL)
    {
      if ((*cmp)(curr->data, data_ref) == 0)
	{
	  if (prev == NULL)
	    *begin = curr->next;
	  else
	    prev->next = curr->next;
	  free(curr);
	  return (1);
	}
      prev = curr;
      curr = curr->next;
    }
  return (0);
}
