/*
** read_user.c for read_user in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Mon May 29 21:27:44 2017 bruel_a
** Last update Tue Jun  6 07:25:23 2017 bruel_a
*/

#include <string.h>
#include <stddef.h>
#include "get_next_line.h"
#include "myirc.h"

static t_irc_cmd	g_cmd[] =
  {
    {"/server", &server_cmd},
    {"/nick", &nick_cmd},
    {"/exit", &exit_cmd},
    {"/quit", &quit_cmd},
    {"/users", &users_cmd},
    {"/part", &part_cmd},
    {"/names", &names_cmd},
    {"/list", &list_cmd},
    {"/join", &join_cmd},
    {"/msg", &msg_cmd},
    {"/accept_file", &accept_file_cmd},
    {"", &default_cmd}
  };

static bool	do_cmd(t_host *host, char **cmd)
{
  int		i;

  i = 0;
  if (host == NULL || cmd == NULL || cmd[0] == NULL)
    return (true);
  while (g_cmd[i].str != NULL)
    {
      if (strcmp(g_cmd[i].str, cmd[0]) == 0)
	return (g_cmd[i].func(host, cmd));
      i++;
    }
  return (g_cmd[10].func(host, cmd));
}

bool	read_user(t_host *host)
{
  char	*str;
  char	**cmd;

  (void)host;
  if ((str = get_next_line(STDIN_FILENO)) == NULL)
    return (false);
  if ((cmd = str_to_wordtab(str, " \t")) == NULL)
    return (false);
  if (!do_cmd(host, cmd))
    return (false);
  freetab(cmd);
  free(str);
  return (true);
}
