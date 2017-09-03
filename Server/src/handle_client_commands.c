/*
** handle_client_commands.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jun  9 21:12:00 2017 bongol_b
** Last update Sun Jun 11 19:12:48 2017 bongol_b
*/

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "myirc.h"
#include "errors.h"
#include "irc_rpl.h"

int		read_client_commands(int sock)
{
  t_message	**msg;
  t_cmd		cmd;
  int		i;

  if ((msg = packet_parser(sock)) == NULL)
    return (true);
  i = 0;
  while (msg[i])
    {
      if (!get_cmd(msg[i]->command, &cmd))
	{
	  packet_send_varg(sock, ERR_UNKNOWNCOMMAND, msg[i]->command);
	  return (true);
	}
      if (is_auth_cmd_allowed(msg[i]->command) || is_client_logged(sock))
	cmd.execute(sock, msg[i]);
      else
	packet_send(sock, ERR_NOTREGISTERED);
      i++;
    }
  return (true);
}

int		answer_client_commands(int sock)
{
  packet_send_buffered(sock);
  return (1);
}
