/*
** tools.c for tools in PSU_2016_myirc
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Fri May 26 08:54:58 2017 bruel_a
** Last update Sun Jun 11 19:16:53 2017 bongol_b
*/

#include <ctype.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include "myirc.h"
#include "errors.h"

static int	initialize_client(int fd)
{
  t_client	*client;

  client = client_create_helper(fd, NULL, UNAUTHENTICATED);
  if (client == NULL || !add_client(client))
    return (dprintf(2, ERR_ADD_CLIENT), 0);
  return (1);
}

bool		irc_accept(int fd)
{
  int		acceptfd;
  socklen_t	addr_len;
  t_sockaddr	addr;

  addr_len = sizeof(addr);
  if ((acceptfd = accept(fd, (struct sockaddr *)&addr, &addr_len)) == ERR_FUNC)
    return (error_handler(false, "accept()", false));
  g_irc.type[acceptfd] = CLIENT;
  initialize_client(acceptfd);
  return (true);
}

bool		close_fd(int fd)
{
  if (close(fd) == ERR_FUNC)
    return (error_handler(false, "close()", false));
  g_irc.type[fd] = FREE;
  return (true);
}

void		to_uppercase_string(char *s)
{
  while(s && *s)
    {
      if (islower(*s))
	*s = toupper(*s);
      s++;
    }
}
