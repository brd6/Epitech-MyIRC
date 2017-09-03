/*
** channel_manager.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 15:35:08 2017 bongol_b
** Last update Sat Jun 10 00:49:39 2017 bongol_b
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "my.h"

t_channel	*channel_create_helper(const char *name,
				       const char *subject)
{
  t_channel	*channel;

  if ((channel = malloc(sizeof(*channel))) == NULL)
    return (NULL);
  channel->name = name ? strdup(name) : NULL;
  channel->subject = subject ? strdup(subject) : NULL;
  channel->nb_client = 0;
  channel->clients = NULL;
  return (channel);
}

int		add_channel(t_channel *channel)
{
  return (my_add_elem_in_list_begin(&g_irc.channels, channel));
}

int		remove_channel(t_channel *channel)
{
  return (my_rm_el_from_list(&g_irc.channels,
			     channel->name,
			     channel_cmp_by_name));
}

int		add_client_in_channel(t_client *client, t_channel *channel)
{
  int		ret;

  ret = my_add_elem_in_list_begin(&channel->clients, client);
  if (ret)
    channel->nb_client++;
  return (ret);
}

int		remove_client_in_channel(t_client *client, t_channel *channel)
{
  int		ret;

  ret = my_rm_el_from_list(&channel->clients,
			   &client->sock_fd,
			   client_cmp_by_sockfd);
  if (ret)
    channel->nb_client--;
  if (channel->nb_client <= 0)
    remove_channel(channel);
  packet_send_varg(client->sock_fd, ":%s!%s@localhost PART :%s",
		   client->nickname,
		   client->username ? client->username : client->nickname,
		   channel->name);
  return (ret);
}
