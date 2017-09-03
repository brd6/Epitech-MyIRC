/*
** cmd_ping.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun  3 17:28:00 2017 bongol_b
** Last update Wed Jun 14 15:46:16 2017 bongol_b
*/

#include "myirc.h"
#include "irc_rpl.h"

int		cmd_ping(int sock, t_message *msg)
{
  t_client	*client;
  char		*nickname;

  if (msg == NULL || msg->params == NULL)
    return (packet_send(sock, ERR_NOORIGIN), 0);
  if ((nickname = extract_first_param(msg->params)) == NULL ||
      (client = get_client_by_nickname(nickname)))
    return (packet_send_varg(sock, ERR_NOSUCHSERVER, nickname), 0);
  //packet_send_varg(sock, "PING %s", msg->params ? msg->params : "");
  return (1);
}
