/*
** tabdup.c for tabdup in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Thu Jun  1 13:46:52 2017 bruel_a
** Last update Thu Jun  1 14:15:17 2017 bruel_a
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"

char	**tabdup(char **tab)
{
  char	**tmp;
  int	i;

  i = 0;
  if ((tmp = malloc(sizeof(char *) * (tablen(tab) + 2))) == NULL)
    return (NULL);
  if (tab == NULL)
    {
      if ((tmp[0] = strdup("")) == NULL)
	return (NULL);
      tmp[1] = NULL;
      return (tmp);
    }
  while (tab[i])
    {
      if ((tmp[i] = strdup(tab[i])) == NULL)
	return (NULL);
      ++i;
    }
  tmp[i] = NULL;
  return (tmp);
}
