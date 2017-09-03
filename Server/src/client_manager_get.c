/*
** client_manager_get.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May 31 17:46:24 2017 bongol_b
** Last update Sat Jun  3 15:01:11 2017 bongol_b
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "my.h"

t_client	*get_client_by_sockfd(int sockfd)
{
  t_client	*clnt;

  clnt = my_find_elm_eq_in_list(g_irc.clients, &sockfd, client_cmp_by_sockfd);
  return (clnt);
}

t_client	*get_client_by_nickname(const char *nickname)
{
  t_client	*c;

  c = my_find_elm_eq_in_list(g_irc.clients,
			     (char *)nickname,
			     client_cmp_by_nickname);
  return (c);
}

t_client	*get_client_by_nickname_check(const char *nickname)
{
  t_client	*c;

  c = my_find_elm_eq_in_list(g_irc.clients,
			     (char *)nickname,
			     client_cmp_by_nickname_check);
  return (c);
}

t_client	*get_client_by_username(const char *username)
{
  t_client	*c;

  c = my_find_elm_eq_in_list(g_irc.clients,
			     (char *)username,
			     client_cmp_by_username);
  return (c);
}

t_client	*get_client_by_username_check(const char *username)
{
  t_client	*c;

  c = my_find_elm_eq_in_list(g_irc.clients,
			     (char *)username,
			     client_cmp_by_username_check);
  return (c);
}
