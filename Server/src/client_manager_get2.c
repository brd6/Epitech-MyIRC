/*
** client_manager_get2.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  3 15:40:23 2017 bongol_b
** Last update Sat Jun  3 15:40:45 2017 bongol_b
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "my.h"

t_client	*get_client_by_sockfd_check(int sockfd)
{
  t_client	*clnt;

  clnt = my_find_elm_eq_in_list(g_irc.clients,
				&sockfd,
				client_cmp_by_sockfd_check);
  return (clnt);
}
