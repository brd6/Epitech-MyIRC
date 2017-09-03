/*
** cmd_names.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 21:07:12 2017 bongol_b
** Last update Sun Jun 11 19:19:43 2017 bongol_b
*/

#include <string.h>
#include "myirc.h"
#include "irc_rpl.h"
#include "my.h"

static void	send_channel_info(int sock, t_channel *channel)
{
  char		buff[BUFF_SIZE];
  t_list	*current;
  t_client	*client;

  current = channel->clients;
  buff[0] = 0;
  while (current)
    {
      client = current->data;
      if (client)
	{
	  strcat(buff, "@");
	  strcat(buff, client->nickname);
	  if (current->next)
	    strcat(buff, " ");
	}
      current = current->next;
    }
  packet_send_varg(sock, RPL_NAMREPLY, channel->name, buff);
  packet_send_varg(sock, RPL_ENDOFNAMES, channel->name);
}

static int	send_channels_info(int sock, char **channel_names)
{
  int		i;
  t_channel	*channel;

  i = 0;
  while (channel_names && channel_names[i])
    {
      if ((channel = get_channel_by_name(channel_names[i])))
	send_channel_info(sock, channel);
      i++;
    }
  return (1);
}

static int	send_all_channels(int sock)
{
  t_list	*current;

  current = g_irc.channels;
  while (current)
    {
      send_channel_info(sock, current->data);
      current = current->next;
    }
  return (1);
}

int		cmd_names(int sock, t_message *msg)
{
  char		**channel_names;

  if (msg->params &&
      (channel_names = my_str_split(msg->params, ",")))
    send_channels_info(sock, channel_names);
  else
    send_all_channels(sock);
  return (1);
}
