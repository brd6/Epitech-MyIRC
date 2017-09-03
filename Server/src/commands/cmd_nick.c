/*
** cmd_nick.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May 31 17:37:00 2017 bongol_b
** Last update Sun Jun 11 19:24:28 2017 bongol_b
*/

#include <string.h>
#include <stdlib.h>
#include "myirc.h"
#include "irc_rpl.h"

static int	relogin_check(int client_fd, t_client *tmp)
{
  t_client	*client;

  if ((client = get_client_by_sockfd(client_fd)) == NULL)
    return (0);
  if (tmp->password == NULL ||
      (client->password != NULL &&
       strcmp(client->password, tmp->password) == 0))
    {
      tmp->sock_fd = client_fd;
      tmp->state = LOGIN_IN_PROGRESS;
      return (2);
    }
  return (packet_send(client_fd, ERR_PASSWDMISMATCH), -1);
}

static int	check_nickname_already_exist(int client_fd,
					     const char *nickname)
{
  t_client	*tmp;

  if ((tmp = get_client_by_nickname(nickname)) == NULL)
    return (0);
  if (tmp->state == AUTHENTIFICATED)
    return (packet_send_varg(client_fd,
			     ERR_NICKCOLLISION,
			     nickname), 1);
  else if (tmp->state == LOGIN_IN_PROGRESS)
    return (packet_send_varg(client_fd,
			     ERR_NICKNAMEINUSE,
			     nickname), 1);
  else
    return relogin_check(client_fd, tmp);
  return (0);
}

static int	handle_nickname_change(int client_fd,
				       char *nickname,
				       char *new_nickname)
{
  t_client	*client;

  if ((client = get_client_by_nickname(nickname)) == NULL)
    {
      return (packet_send_varg(client_fd,
			       ERR_ERRONEUSNICKNAME,
			       nickname), 0);
    }
  free(client->nickname);
  client->nickname = new_nickname;
  return (1);
}

static int	handle_nickname_add(int client_fd,
				    char *nickname)
{
  t_client	*client;

  if ((client = get_client_by_sockfd(client_fd)) == NULL)
    {
      return (packet_send_varg(client_fd,
			       ERR_ERRONEUSNICKNAME,
			       nickname), 0);
    }
  client->nickname = nickname;
  return (1);
}

int		cmd_nick(int sock, t_message *msg)
{
  char		*nickname;
  int		ret;
  t_client	*client;

  if ((nickname = extract_first_param(msg->params)) == NULL)
    return (packet_send_varg(sock, ERR_NONICKNAMEGIVEN), 0);
  if (strlen(nickname) > NICKNAME_MAX_LEN)
    return (packet_send_varg(sock, ERR_ERRONEUSNICKNAME, nickname), 0);
  if ((ret = check_nickname_already_exist(sock, nickname)) == 1 || ret == -1)
    return (0);
  if (ret != 2)
    {
      if (msg->prefix != NULL)
	ret = handle_nickname_change(sock, msg->prefix, nickname);
      else
	ret = handle_nickname_add(sock, nickname);
      if (!ret)
	return (0);
    }
  client = get_client_by_sockfd(sock);
  packet_send_varg(sock, ":%s!%s@* NICK %s",
		   client->nickname,
		   client->username ? client->username : client->nickname,
		   client->nickname);
  return (ret);
}
