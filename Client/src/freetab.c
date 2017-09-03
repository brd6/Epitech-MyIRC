/*
** freetab.c for freetab in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Mon May 29 17:21:36 2017 bruel_a
** Last update Thu Jun  1 14:15:45 2017 bruel_a
*/

#include <stdlib.h>

void	freetab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return ;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}
