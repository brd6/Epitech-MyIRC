/*
** server.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Tue Jun  6 21:09:14 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"

bool	quit_cmd(t_host *host, char **cmd)
{
  char	*str;

  if (host->fd == -1)
    {
      write(STDERR_FILENO, ERR_NO_CO, strlen(ERR_NO_CO));
      return (true);
    }
  else if (cmd[1] == NULL || cmd[1][0] == '\0')
    write(host->fd, QUIT_CMD, strlen(QUIT_CMD));
  else
    {
      asprintf(&str, QUIT_CMD_MSG, cmd[1]);
      write(host->fd, str, strlen(str));
      free(str);
    }
  host->fd = -1;
  free(host->in);
  free(host->out);
  if ((host->in = strdup("")) == NULL ||
      (host->out = strdup("")) == NULL)
    return (false);
  return (true);
}
