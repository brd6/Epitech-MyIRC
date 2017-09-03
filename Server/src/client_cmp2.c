/*
** client_cmp2.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  3 15:26:55 2017 bongol_b
** Last update Sat Jun  3 15:27:34 2017 bongol_b
*/

#include "myirc.h"

int		client_cmp_by_sockfd_check(t_client *client, int *sock_fd)
{
  return (!(client->sock_fd == *sock_fd && client->state == LOGIN_IN_PROGRESS));
}
