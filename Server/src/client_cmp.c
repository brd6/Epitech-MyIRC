/*
** client_cmp.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  3 11:42:44 2017 bongol_b
** Last update Sun Jun 11 19:25:58 2017 bongol_b
*/

#include <string.h>
#include "myirc.h"

int		client_cmp_by_sockfd(t_client *client, int *sock_fd)
{
  return (!(client->sock_fd == *sock_fd && client->state != LOGIN_IN_PROGRESS));
}

int		client_cmp_by_nickname(t_client *client, char *nickname)
{
  return (!(client->nickname &&
	    strcmp(client->nickname, nickname) == 0));
}

int		client_cmp_by_nickname_check(t_client *client, char *nickname)
{
  return (!(client->nickname &&
	    client->state == LOGIN_IN_PROGRESS &&
	    strcmp(client->nickname, nickname) == 0));
}

int		client_cmp_by_username(t_client *client, char *username)
{
  return (!(username &&
	    client->username &&
	    strcmp(client->username, username) == 0));
}

int		client_cmp_by_username_check(t_client *client, char *username)
{
  return (!(username &&
	    client->username &&
	    strcmp(client->username, username) == 0 &&
	    client->state != LOGIN_IN_PROGRESS));
}
