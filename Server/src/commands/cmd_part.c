/*
** cmd_part.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jun  2 17:46:36 2017 bongol_b
** Last update Sun Jun 11 19:20:39 2017 bongol_b
*/

#include "myirc.h"
#include "irc_rpl.h"
#include "my.h"

static int	remove_client_in_channels(int sock, char **channel_names)
{
  int		i;
  t_channel	*channel;
  t_client	*client;

  if ((client = get_client_by_sockfd(sock)) == NULL)
    return (0);
  i = 0;
  while (channel_names && channel_names[i])
    {
      if ((channel = get_channel_by_name(channel_names[i])) == NULL)
	packet_send_varg(sock, ERR_NOSUCHCHANNEL, channel_names[i]);
      else if (!is_client_in_channel(client, channel))
	packet_send_varg(sock, ERR_NOTONCHANNEL, channel_names[i]);
      else
        remove_client_in_channel(client, channel);
      i++;
    }
  return (1);
}

int		cmd_part(int sock, t_message *msg)
{
  char		**channel_names;

  if (msg->params == NULL ||
      (channel_names = my_str_split(msg->params, ",")) == NULL)
    {
      packet_send_varg(sock, ERR_NEEDMOREPARAMS, msg->command);
      return (0);
    }
  remove_client_in_channels(sock, channel_names);
  return (1);
}
