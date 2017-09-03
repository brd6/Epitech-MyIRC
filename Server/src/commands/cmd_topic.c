/*
** cmd_topic.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  3 16:51:49 2017 bongol_b
** Last update Sun Jun 11 19:22:53 2017 bongol_b
*/

#include <stdlib.h>
#include "myirc.h"
#include "irc_rpl.h"

static int	change_channel_topic(char *name, char *new_topic)
{
  t_channel	*channel;

  if ((channel = get_channel_by_name(name)) == NULL)
    return (0);
  free(channel->subject);
  channel->subject = new_topic;
  return (1);
}

static int	send_channel_topic(int sock, char *name)
{
  t_channel	*channel;

  if ((channel = get_channel_by_name(name)) == NULL)
    return (0);
  if (channel->subject == NULL)
    packet_send_varg(sock, RPL_NOTOPIC, channel->name);
  else
    packet_send_varg(sock, RPL_TOPIC, channel->name, channel->subject);
  return (1);
}

int		cmd_topic(int sock, t_message *msg)
{
  char		*new_topic;
  char		*channel_name;

  if (msg == NULL ||
      msg->params == NULL ||
      (channel_name = extract_first_param(msg->params)) == NULL)
    return (packet_send_varg(sock, ERR_NEEDMOREPARAMS, msg->command), 0);
  if ((new_topic = extract_second_prefix(msg->params)) != NULL)
    return (change_channel_topic(channel_name, new_topic));
  return (send_channel_topic(sock, channel_name));
}
