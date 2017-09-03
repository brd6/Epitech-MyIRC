/*
** client_manager.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May 31 16:14:35 2017 bongol_b
** Last update Sat Jun 10 00:19:44 2017 bongol_b
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "my.h"

t_client	*client_create_helper(int sock_fd,
				      const char *nickname,
				      t_client_state state)
{
  t_client	*client;
  char		*name;

  if ((client = malloc(sizeof(*client))) == NULL)
    return (NULL);
  name = nickname ? strdup(nickname) : generate_client_name();
  client->sock_fd = sock_fd;
  client->nickname = name;
  client->realname = NULL;
  client->username = NULL;
  client->state = state;
  client->password = NULL;
  queue_init(&client->packets);
  return (client);
}

void		logout_client(t_client *client)
{
  if (!client)
    return ;
  client->sock_fd = -1;
  client->state = UNAUTHENTICATED;
}

int		add_client(t_client *client)
{
  return (my_add_elem_in_list_begin(&g_irc.clients, client));
}

int		is_client_logged(int sock)
{
  t_client	*client;

  if ((client = get_client_by_sockfd(sock)) == NULL)
    return (0);
  return (client->state == AUTHENTIFICATED);
}

int		is_client_in_channel(t_client *client, t_channel *channel)
{
  t_client	*clnt;

  clnt = my_find_elm_eq_in_list(channel->clients,
				&client->sock_fd,
				client_cmp_by_sockfd);
  return (clnt != NULL);
}
