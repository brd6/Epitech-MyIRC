/*
** select_utils.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jun  9 20:58:58 2017 bongol_b
** Last update Fri Jun  9 21:04:08 2017 bongol_b
*/

#include "myirc.h"

void	init_client_socks()
{
  int	i;

  i = 0;
  while (i < MAX_CLIENT_SOCK)
    g_irc.type[i++] = WAITING;
}

void	init_select_clients(fd_set *readfds,
			    fd_set *writefds,
			    int *max_fd)
{
  int	i;

  FD_ZERO(readfds);
  FD_ZERO(writefds);
  FD_SET(g_irc.server_fd, readfds);
  *max_fd = g_irc.server_fd;
  i = 0;
  while (i < MAX_CLIENT_SOCK)
    {
      if (g_irc.type[i] != WAITING)
	{
	  FD_SET(i, readfds);
	  FD_SET(i, writefds);
	}
      if (i > *max_fd)
	*max_fd = i;
      i++;
    }
}
