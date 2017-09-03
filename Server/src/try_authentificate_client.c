/*
** try_authentificate_client.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 00:32:28 2017 bongol_b
** Last update Sun Jun 11 19:09:36 2017 bongol_b
*/

#include "myirc.h"
#include "irc_rpl.h"

static void	send_welcome_message(t_client *client)
{
  packet_send_varg(client->sock_fd,
		   RPL_WELCOME,
		   client->nickname,
		   client->username,
		   "localhost");
}

int		try_authentificate_client(t_client *client)
{
  t_client	*tmp;

  if (client->nickname != NULL &&
      client->realname != NULL &&
      client->username != NULL &&
      client->state != AUTHENTIFICATED)
    {
      if ((tmp = get_client_by_sockfd_check(client->sock_fd)) != NULL)
	{
	  tmp->username = client->username;
	  tmp->realname = client->realname;
	  remove_client(client);
	  client = tmp;
	}
      client->state = AUTHENTIFICATED;
      send_welcome_message(client);
      return (1);
    }
  return (0);
}
