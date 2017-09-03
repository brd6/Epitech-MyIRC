/*
** server.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Tue Jun  6 21:08:29 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"

bool	part_cmd(t_host *host, char **cmd)
{
  char	*str;

  if (cmd[1] == NULL || cmd[1][0] == '\0')
    write(STDERR_FILENO, ERR_NO_ARG, strlen(ERR_NO_ARG));
  else if (host->fd == -1)
    write(STDERR_FILENO, ERR_NO_CO, strlen(ERR_NO_CO));
  else
    {
      asprintf(&str, PART_CMD, cmd[1]);
      write(host->fd, str, strlen(str));
      free(str);
    }
  return (true);
}
