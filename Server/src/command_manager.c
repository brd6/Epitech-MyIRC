/*
** command_manager.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Tue May 30 17:02:15 2017 bongol_b
** Last update Wed Jun 14 15:51:58 2017 bongol_b
*/

#include <string.h>
#include <stdio.h>
#include "myirc.h"

static t_cmd	g_cmds[] = {
  {"PASS", cmd_pass},
  {"NICK", cmd_nick},
  {"USER", cmd_user},
  {"QUIT", cmd_quit},
  {"JOIN", cmd_join},
  {"NAMES", cmd_names},
  {"PART", cmd_part},
  {"LIST", cmd_list},
  {"TOPIC", cmd_topic},
  {"PING", cmd_ping},
  {"USERS", cmd_users},
  {"PRIVMSG", cmd_privmsg},
  {NULL, NULL}
};

static int	get_command_index(const char *cmd)
{
  int		i;

  i = 0;
  while (cmd && g_cmds[i].command)
    {
      if (strcasecmp(g_cmds[i].command, cmd) == 0)
	return (i);
      i++;
    }
  return (UNKNOW_CMD_IDX);
}

int		get_cmd(const char *cmd_name, t_cmd *cmd)
{
  int		i;

  if ((i = get_command_index(cmd_name)) == UNKNOW_CMD_IDX)
    return (0);
  *cmd = g_cmds[i];
  return (1);
}

int		is_auth_cmd_allowed(const char *cmd)
{
  int		check;

  check = (strcasecmp(cmd, "PASS") == 0 ||
	   strcasecmp(cmd, "NICK") == 0 ||
	   strcasecmp(cmd, "USER") == 0 ||
	   strcasecmp(cmd, "QUIT") == 0 ||
	   strcasecmp(cmd, "PONG") == 0);
  return (check);
}
