/*
** server.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Tue Jun  6 21:10:28 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"

static bool	is_valid_user(char *str, char **users)
{
  int		i;

  i = 0;
  if (users == NULL)
    return (false);
  while (users[i] != NULL)
    {
      if (strcmp(str, users[i]) == 0)
	return (true);
      ++i;
    }
  return (false);
}

static bool	send_msg(t_host *host, char **cmd)
{
  char	*str;
  int	i;

  i = 1;
  asprintf(&str, MSG);
  while (cmd[i] != NULL)
    {
      if (i == 2 && cmd[i + 1] != NULL &&
	  !is_valid_user(cmd[i], host->users))
	{
	  write(STDERR_FILENO, ERR_NICK_INV, strlen(ERR_NICK_INV));
	  free(str);
	  return (true);
	}
      else if (i == 2)
	asprintf(&str, "%s :%s", str, cmd[i++]);
      else
	asprintf(&str, "%s %s", str, cmd[i++]);
    }
  asprintf(&str, "%s\r\n", str);
  write(host->fd, str, strlen(str));
  free(str);
  return (true);
}

bool	msg_cmd(t_host *host, char **cmd)
{
  if (cmd[1] == NULL || cmd[1][0] == '\0')
    write(STDERR_FILENO, ERR_NO_ARG, strlen(ERR_NO_ARG));
  else if (host->fd == -1)
    write(STDERR_FILENO, ERR_NO_CO, strlen(ERR_NO_CO));
  else
    return (send_msg(host, cmd));
  return (true);
}
