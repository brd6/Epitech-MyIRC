/*
** str_to_wordtab.c for str_to_wordtab in PSU_2016_myftp
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May  9 22:37:25 2017 bruel_a
** Last update Fri May 19 13:58:54 2017 bruel_a
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	**str_to_wordtab(char *str, const char *by)
{
  char	**tab;
  char	*pch;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (strlen(str) + 1))) == NULL)
    return (NULL);
  pch = strtok(str, by);
  tab[i] = pch;
  while (pch != NULL)
    {
      if ((tab[i++] = strdup(pch)) == NULL)
	return (NULL);
      pch = strtok(NULL, by);
    }
  tab[i] = NULL;
  return (tab);
}
