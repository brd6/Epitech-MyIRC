/*
** my_add_elem_in_list_begin.c for my_add_elem_in_list_begin in /home/bongol_b/rendu_ok/PSU_2015_minishell1
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Jan 19 12:29:15 2016 Berdrigue BONGOLO BETO
** Last update Sun Apr  3 02:58:21 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

int		my_add_elem_in_list_begin(t_list **begin, void *data)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (0);
  new->data = data;
  new->next = *begin;
  *begin = new;
  return (1);
}
