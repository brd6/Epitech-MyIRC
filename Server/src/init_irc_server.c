/*
** init_irc_server.c for init_irc_server in PSU_2016_myirc/Server
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 23 14:53:08 2017 bruel_a
** Last update Tue Jun  6 02:03:05 2017 bongol_b
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include "myirc.h"
#include "errors.h"

static void	set_irc_type()
{
  int		i;

  i = 0;
  while (i < FD_MAX)
    {
      g_irc.type[i] = FREE;
      ++i;
    }
}

static int	set_reuse_addr_mode(int sock)
{
  int		optval;
  int		ret;

  optval = 1;
  ret = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
  return (ret != -1);
}

static void	init_irc(int sockfd)
{
  set_irc_type();
  g_irc.type[sockfd] = WAITING;
  g_irc.server_fd = sockfd;
  g_irc.clients = NULL;
  g_irc.channels = NULL;
}

bool		init_irc_server(char *port)
{
  t_protoent	*protoent;
  t_sockaddr	addr;
  int		sockfd;

  if ((g_irc.port = atoi(port)) <= MIN_PORT || g_irc.port >= MAX_PORT)
    return (false);
  if ((protoent = getprotobyname(PROTOCOL_TYPE)) == NULL)
    return (false);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(g_irc.port);
  addr.sin_addr.s_addr = INADDR_ANY;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, protoent->p_proto)) == ERR_FUNC)
    return (error_handler(false, "socket()", false));
  if (set_reuse_addr_mode(sockfd) == 0 ||
      bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == ERR_FUNC)
    return (error_handler(false, "bind()", false));
  if (listen(sockfd, BACKLOG) == ERR_FUNC)
    return (error_handler(false, "listen()", false));
  if (sockfd >= FD_MAX)
    return (error_handler(true, TOO_MUCH_FD, false));
  init_irc(sockfd);
  return (1);
}
