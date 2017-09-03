/*
** client_manager2.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  3 15:34:40 2017 bongol_b
** Last update Sun Jun 11 19:11:02 2017 bongol_b
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "my.h"

int		remove_a_client(t_client *client, int *sock_fd)
{
  int		is_client;

  is_client = (client->sock_fd == *sock_fd);
  if (!is_client)
    return (1);
  free(client->nickname);
  free(client->realname);
  free(client->username);
  free(client->password);
  queue_free(&client->packets);
  return (0);
}

int		remove_client(t_client *client)
{
  return (my_rm_el_from_list(&g_irc.clients,
			     &client->sock_fd,
			     client_cmp_by_sockfd));
}
