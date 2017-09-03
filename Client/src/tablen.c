/*
** tablen.c for tablen in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Thu Jun  1 13:49:25 2017 bruel_a
** Last update Thu Jun  1 14:14:47 2017 bruel_a
*/

#include <stddef.h>

int	tablen(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    ++i;
  return (i);
}
