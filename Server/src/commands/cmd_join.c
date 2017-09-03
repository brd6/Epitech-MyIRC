/*
** cmd_join.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 15:49:04 2017 bongol_b
** Last update Sun Jun 11 19:19:09 2017 bongol_b
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "my.h"
#include "irc_rpl.h"

static char	**extract_channel_names_in_params(const char *params)
{
  char		**tmp;
  char		**names;

  tmp = NULL;
  names = NULL;
  if (params == NULL ||
      (tmp = my_str_split(params, " \t")) == NULL ||
      tmp[0] == NULL ||
      (names = my_str_split(tmp[0], ",")) == NULL)
    {
      my_free_wordtab(tmp);
      return (NULL);
    }
  return (names);
}

static void	send_join_response(int sock,
				   t_channel *channel)
{
  t_message	msg;

  msg.params = NULL;
  msg.command = strdup("JOIN");
  send_message_to_channel(sock, channel->name, &msg);
  free(msg.command);
  if (channel->subject != NULL)
    packet_send_varg(sock, RPL_TOPIC, channel->name, channel->subject);
  else
    packet_send_varg(sock, RPL_NOTOPIC, channel->name);
  msg.command = NULL;
  msg.prefix = NULL;
  msg.params = channel->name;
  cmd_names(sock, &msg);
}

static int	check_bad_channel_mask(int sock, const char *name)
{
  if (strlen(name) > CHANNEL_NAME_MAX_LEN ||
      strstr(name, CHANNEL_NAME_FORBIDEEN_CHARS) != NULL)
    {
      packet_send_varg(sock, ERR_BADCHANMASK, name);
      return (0);
    }
  return (1);
}

static int	add_client_in_channels(int sock, char **channel_names)
{
  int		i;
  t_client	*client;
  t_channel	*channel;
  int		check;

  i = 0;
  check = 0;
  if ((client = get_client_by_sockfd(sock)) == NULL)
    return (0);
  while (channel_names && channel_names[i])
    {
      check = check_bad_channel_mask(sock, channel_names[i]);
      channel = check ? get_or_create_channel(channel_names[i]) : NULL;
      if (channel && (check = is_client_in_channel(client, channel)))
	{
	  packet_send_varg(sock,
			   ERR_USERONCHANNEL,
			   client->username,
			   channel->name);
	}
      if (channel && check == 0 && add_client_in_channel(client, channel))
	send_join_response(sock, channel);
      i++;
    }
  return (1);
}

int		cmd_join(int sock, t_message *msg)
{
  char		**channel_names;

  if ((channel_names = extract_channel_names_in_params(msg->params)) == NULL)
    {
      packet_send_varg(sock, ERR_NEEDMOREPARAMS, msg->command);
      return (0);
    }
  if (!add_client_in_channels(sock, channel_names))
    {
      my_free_wordtab(channel_names);
      channel_names = NULL;
      return (0);
    }
  my_free_wordtab(channel_names);
  return (1);
}
