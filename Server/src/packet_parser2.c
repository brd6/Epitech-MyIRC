/*
** packet_parser2.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun  4 00:56:33 2017 bongol_b
** Last update Sun Jun  4 02:12:02 2017 bongol_b
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"

char		*extract_second_prefix(const char *params)
{
  int		i;
  int		cpt;

  if (params == NULL)
    return (NULL);
  i = 0;
  cpt = 0;
  while (params && params[i])
    {
      if (params[i] == PREFIX_START_CHAR)
	cpt++;
      if (params[i] == PREFIX_START_CHAR && cpt > 0)
	break ;
      i++;
    }
  if (params[i] == 0 || params[i + 1] == 0)
    return (NULL);
  i++;
  return (strdup(&params[i]));
}

char		**separe_param_and_second_prefix(const char *params)
{
  char		**results;
  int		i;
  int		j;

  if (params == NULL ||
	(results = malloc(sizeof(*results) * 3)) == NULL ||
	(results[0] = malloc(sizeof(**results) * (strlen(params) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (params && params[i] && params[i] != PREFIX_START_CHAR)
    results[0][j++] = params[i++];
  results[0][j] = 0;
  if (params[i] != PREFIX_START_CHAR)
    results[1] = NULL;
  else
    results[1] = strdup(&params[i + 1]);
  results[2] = NULL;
  return (results);
}
