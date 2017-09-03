/*
** hosts.c for hosts in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Mon May 29 17:07:32 2017 bruel_a
** Last update Tue Jun  6 07:19:49 2017 bruel_a
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myirc.h"

t_host		init_host(void)
{
  t_host	host;

  host.fd = -1;
  if ((host.in = strdup("")) == NULL ||
      (host.out = strdup("")) == NULL)
    return (host);
  host.users = NULL;
  return (host);
}

void	host_out(t_host *host)
{
  if (host->fd > -1)
    close(host->fd);
  if (host->users != NULL)
    freetab(host->users);
  free(host->in);
  free(host->out);
}
