/*
** channel_cmp.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  3 11:48:58 2017 bongol_b
** Last update Sun Jun  4 11:54:47 2017 bongol_b
*/

#include <string.h>
#include "myirc.h"

int		channel_cmp_by_name(t_channel *channel, char *name)
{
  return (!(name && channel->name && strcmp(channel->name, name) == 0));
}
