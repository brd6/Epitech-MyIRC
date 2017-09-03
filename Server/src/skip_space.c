/*
** skip_space.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 00:47:43 2017 bongol_b
** Last update Thu Jun  1 00:48:01 2017 bongol_b
*/

#include "myirc.h"

int		skip_space(const char *str)
{
  int		i;

  i = 0;
  while ((str && str[i]) &&
	 (str[i] == PACKET_MSG_SEPARATORS[0] ||
	  str[i] == PACKET_MSG_SEPARATORS[1]))
    i++;
  return (i);
}
