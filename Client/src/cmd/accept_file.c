/*
** server.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Tue Jun  6 21:10:55 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"

static bool	add_file(t_host *host, char *cmd)
{
  char		**files;

  if ((files = tabdup(host->users)) == NULL)
    return (false);
  if ((files[tablen(files) - 1] = strdup(cmd)) == NULL)
    return (false);
  files[tablen(files)] = NULL;
  freetab(host->users);
  host->users = files;
  return (true);
}

bool	accept_file_cmd(t_host *host, char **cmd)
{
  char	*str;

  if (cmd[1] == NULL || cmd[1][0] == '\0')
    write(STDERR_FILENO, ERR_NO_ARG, strlen(ERR_NO_ARG));
  else if (host->fd == -1)
    write(STDERR_FILENO, ERR_NO_CO, strlen(ERR_NO_CO));
  else
    {
      if (!add_file(host, cmd[1]))
	return (false);
      asprintf(&str, FILE_ADD_CMD, cmd[1]);
      write(STDOUT_FILENO, str, strlen(str));
      free(str);
    }
  return (true);
}
