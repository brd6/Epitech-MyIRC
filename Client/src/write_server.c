/*
** write_server.c for write_server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Mon May 29 21:39:13 2017 bruel_a
** Last update Tue Jun  6 07:22:34 2017 bruel_a
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "myirc.h"

static bool	clean_host(t_host *host)
{
  if (host->in != NULL && host->in[0] != '\0')
    {
      free(host->in);
      if ((host->in = strdup("")) == NULL)
	return (false);
    }
  if (host->out != NULL && host->out[0] != '\0')
    {
      free(host->out);
      if ((host->out = strdup("")) == NULL)
	return (false);
    }
  return (true);
}

bool	write_server(t_host *host)
{
  int	i;

  i = 0;
  if (host->out[0] != '\0')
    write(host->fd, host->out, strlen(host->out));
  while (host->in != NULL && host->in[i])
    {
      if (host->in[i] != '\r')
	write(STDOUT_FILENO, &host->in[i], 1);
      ++i;
    }
  if (host->in != NULL && host->in[0] != '\0' &&
      host->in[strlen(host->in) - 1] != '\n')
    write(STDOUT_FILENO, "\n", 1);
  return (clean_host(host));
}
