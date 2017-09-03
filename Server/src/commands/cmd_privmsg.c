/*
** cmd_privmsg.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun  4 00:43:48 2017 bongol_b
** Last update Sun Jun 11 19:24:50 2017 bongol_b
*/

#include <stdio.h>
#include <string.h>
#include "myirc.h"
#include "my.h"
#include "irc_rpl.h"

static char	**extract_dest_names_in_params(const char *params)
{
  char		**names;

  names = NULL;
  if (params == NULL ||
      (names = my_str_split(params, ", \t")) == NULL)
    return (NULL);
  return (names);
}

static int	send_message_to_client(int sock,
				       char *name,
				       t_message *msg,
				       t_client *dest)
{
  char		to_send[BUFF_SIZE];
  t_client	*sender;

  if (msg == NULL || (sender = get_client_by_sockfd(sock)) == NULL)
    return (0);
  if (dest == NULL && (dest = get_client_by_nickname(name)) == NULL)
    return (packet_send_varg(sock, ERR_NOSUCHNICK, name), 0);
  if (dest->state != AUTHENTIFICATED)
    return (packet_send_varg(sock, ERR_NOSUCHNICK, name), 0);
  to_uppercase_string(msg->command);
  sprintf(to_send, ":%s!%s@localhost %s %s :%s",
	  sender->nickname,
	  sender->username ? sender->username : sender->nickname,
	  msg->command,
	  name,
	  msg->params ? msg->params : "");
  packet_send_varg(dest->sock_fd, to_send);
  return (1);
}

int		send_message_to_channel(int sock, char *name, t_message *msg)
{
  t_channel	*channel;
  t_list	*tmp;

  if ((channel = get_channel_by_name(name)) == NULL)
    return (packet_send_varg(sock, ERR_NOSUCHNICK, name), 0);
  tmp = channel->clients;
  while (tmp)
    {
      send_message_to_client(sock, channel->name, msg, tmp->data);
      tmp = tmp->next;
    }
  return (1);
}

static int	send_messages(int sock, char **dest_names, t_message *msg)
{
  int		i;

  i = 0;
  while (dest_names && dest_names[i])
    {
      if (dest_names[i][0] == CHANNEL_LOCAL_SYMBOL ||
	  dest_names[i][0] == CHANNEL_NETWORK_SYMBOL)
	send_message_to_channel(sock, dest_names[i], msg);
      else
	send_message_to_client(sock, dest_names[i], msg, NULL);
      i++;
    }
  return (1);
}

int		cmd_privmsg(int sock, t_message *msg)
{
  char		**dest_names;
  char		*msg_to_send;
  char		**tmp;
  t_message	to_send;

  if ((tmp = separe_param_and_second_prefix(msg->params)) == NULL ||
      (dest_names = extract_dest_names_in_params(tmp[0])) == NULL)
    return (packet_send_varg(sock, ERR_NORECIPIENT, msg->command), 0);
  if ((msg_to_send = tmp[1]) == NULL)
    return (packet_send_varg(sock, ERR_NOTEXTTOSEND), 0);
  to_send.command = msg->command;
  to_send.params = msg_to_send;
  send_messages(sock, dest_names, &to_send);
  my_free_wordtab(tmp);
  return (1);
}
