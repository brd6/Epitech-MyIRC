/*
** cmd_pass.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May 31 01:08:07 2017 bongol_b
** Last update Sun Jun 11 19:23:44 2017 bongol_b
*/

#include <string.h>
#include "myirc.h"
#include "irc_rpl.h"

int		cmd_pass(int sock, t_message *msg)
{
  t_client	*client;

  if ((client = get_client_by_sockfd(sock)) == NULL)
    return (0);
  if (client->state == AUTHENTIFICATED)
    {
      packet_send(sock, ERR_ALREADYREGISTRED);
      return (0);
    }
  if (msg->params &&
      (client->password = strdup(msg->params)) == NULL)
    client->password = NULL;
  return (1);
}
