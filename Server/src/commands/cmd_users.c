/*
** cmd_users.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  3 17:45:24 2017 bongol_b
** Last update Sun Jun  4 12:12:01 2017 bongol_b
*/

#include "myirc.h"
#include "irc_rpl.h"

int		cmd_users(int sock, t_message *msg)
{
  t_list	*tmp;
  t_client	*client;

  packet_send(sock, RPL_USERSSTART);
  tmp = g_irc.clients;
  while (tmp)
    {
      client = tmp->data;
      packet_send_varg(sock, RPL_USERS, client->nickname);
      tmp = tmp->next;
    }
  packet_send_varg(sock, RPL_ENDOFUSERS, client->nickname);
  (void)msg;
  return (1);
}
