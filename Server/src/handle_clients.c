/*
** handle_clients.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jun  9 21:07:22 2017 bongol_b
** Last update Sun Jun 11 19:26:27 2017 bongol_b
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
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

static int	accept_new_client()
{
  int		sock;

  if ((sock = accept(g_irc.server_fd, NULL, NULL)) == -1)
    return (dprintf(2, ERR_SOCKET_ACCEPT), 0);
  if (sock > MAX_CLIENT_SOCK)
    return (close_client_connection(sock), 1);
  g_irc.type[sock] = CLIENT;
  initialize_client(sock);
  return (1);
}

static void	handle_current_clients(fd_set *readfds, fd_set *writefds)
{
  int		sock;

  sock = 0;
  while (sock < MAX_CLIENT_SOCK)
    {
      if (FD_ISSET(sock, readfds) && g_irc.type[sock] != WAITING)
	read_client_commands(sock);
      else if (FD_ISSET(sock, writefds) && g_irc.type[sock] != WAITING)
	answer_client_commands(sock);
      sock++;
    }
}

void		close_client_connection(int sock)
{
  close(sock);
  g_irc.type[sock] = WAITING;
}

int		handle_clients()
{
  int		max_fd;
  fd_set	readfds;
  fd_set	writefds;

  init_select_clients(&readfds,
		      &writefds,
		      &max_fd);
  if (select(max_fd + 1, &readfds, &writefds, NULL, NULL) == -1)
    return (0);
  if (FD_ISSET(g_irc.server_fd, &readfds) && !accept_new_client())
    return (0);
  handle_current_clients(&readfds, &writefds);
  return (1);
}
