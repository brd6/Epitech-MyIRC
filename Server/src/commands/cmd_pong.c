/*
** cmd_pong.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 12:12:35 2017 bongol_b
** Last update Sat Jun  3 17:41:26 2017 bongol_b
*/

#include "myirc.h"

int		cmd_pong(int sock, t_message *msg)
{
  packet_send_varg(sock, "PING :%s", msg->params);
  return (1);
}
