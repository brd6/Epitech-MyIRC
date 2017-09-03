/*
** channel_manager_get.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 17:44:16 2017 bongol_b
** Last update Sat Jun  3 12:00:53 2017 bongol_b
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "my.h"

t_channel	*get_channel_by_name(const char *name)
{
  t_channel	*c;

  c = my_find_elm_eq_in_list(g_irc.channels,
			     (char *)name,
			     channel_cmp_by_name);
  return (c);
}

t_channel	*get_or_create_channel(const char *name)
{
  t_channel	*channel;

  if (name == NULL ||
      (name[0] != CHANNEL_LOCAL_SYMBOL && name[0] != CHANNEL_NETWORK_SYMBOL))
    return (NULL);
  if ((channel = get_channel_by_name(name)) == NULL &&
      ((channel = channel_create_helper(name, NULL)) == NULL ||
       add_channel(channel) == 0))
    return (NULL);
  return (channel);
}
