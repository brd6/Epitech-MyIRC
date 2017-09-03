/*
** read_server.c for read_server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Mon May 29 21:10:26 2017 bruel_a
** Last update Wed May 31 11:19:53 2017 bruel_a
*/

#include <string.h>
#include "myirc.h"
#include "get_next_line.h"

bool	read_server(t_host *host)
{
  char	*str;
  bool	state;

  state = false;
  if ((str = get_next(host->fd)) != NULL)
    {
      state = true;
      asprintf(&host->in, "%s%s", host->in, str);
      free(str);
    }
  if (state == false)
    return (false);
  return (true);
}
