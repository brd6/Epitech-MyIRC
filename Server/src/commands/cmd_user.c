/*
** cmd_user.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 00:34:14 2017 bongol_b
** Last update Wed Jun 14 12:19:08 2017 bongol_b
*/

#include "myirc.h"
#include "irc_rpl.h"
#include "my.h"

static int	update_client(t_client *client,
			      char *username,
			      char *realname)
{
  client->username = username;
  client->realname = realname;
  if (client->state == UNAUTHENTICATED)
    client->state = LOGIN_IN_PROGRESS;
  return (1);
}

static int	get_username_and_realname(int sock,
					  t_message *msg,
					  char **username,
					  char **realname)
{
  char		**datas;
  char		**params;

  if (msg->params == NULL ||
      (datas = my_str_split(msg->params, ":")) == NULL ||
       datas[0] == NULL ||
      (params = my_str_split(datas[0], " \t")) == NULL ||
      (datas[1] == NULL && my_wordtab_count((const char **)params) < 3))
    return (packet_send_varg(sock,
			     ERR_NEEDMOREPARAMS,
			     msg->command), 0);
  if (datas[1] != NULL)
    *realname = datas[1];
  else
    *realname = params[3];
  *username = params[0];
  return (*realname && *username);
}

int		cmd_user(int sock, t_message *msg)
{
  char		*username;
  t_client	*client;
  char		*realname;
  t_client	*tmp;

  realname = NULL;
  username = NULL;
  if (get_username_and_realname(sock, msg, &username, &realname) == 0)
    return (0);
  if ((tmp = get_client_by_username(username)) &&
      tmp->state != LOGIN_IN_PROGRESS)
    return (packet_send_varg(sock, ERR_ALREADYREGISTRED), 0);
  if ((msg->prefix && (client = get_client_by_nickname(msg->prefix)) == NULL) ||
      ((client = get_client_by_sockfd(sock)) == NULL))
    return (0);
  if ((tmp = get_client_by_sockfd_check(sock)) != NULL)
    client = tmp;
  update_client(client, username, realname);
  return (try_authentificate_client(client));
}
