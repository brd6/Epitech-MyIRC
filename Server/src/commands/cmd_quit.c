/*
** cmd_quit.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 01:45:33 2017 bongol_b
** Last update Sun Jun 11 19:22:43 2017 bongol_b
*/

#include <stdlib.h>
#include <unistd.h>
#include "myirc.h"

int		cmd_quit(int sock, t_message *msg)
{
  char		*quit_msg;
  t_client	*client;

  close_client_connection(sock);
  if ((client = get_client_by_sockfd(sock)) == NULL)
    return (0);
  logout_client(client);
  if (msg == NULL)
    return (0);
  quit_msg = extract_second_prefix(msg->params);
  free(quit_msg);
  remove_client(client);
  return (1);
}
