/*
** list.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Tue Jun  6 21:09:04 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"

bool	list_cmd(t_host *host, char **cmd)
{
  char	*str;

  if (host->fd == -1)
    write(STDERR_FILENO, ERR_NO_CO, strlen(ERR_NO_CO));
  else
    {
      if (cmd[1] != NULL && cmd[1][0] != '\0')
	asprintf(&str, LIST_CMD, cmd[1]);
      else
	asprintf(&str, LIST);
      write(host->fd, str, strlen(str));
      free(str);
    }
  return (true);
}
