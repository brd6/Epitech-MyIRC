/*
** loop.c for loop in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Mon May 29 17:14:19 2017 bruel_a
** Last update Mon May 29 22:16:14 2017 bruel_a
*/

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "myirc.h"

static void	is_connected(t_host *host,
			     fd_set *fd_r,
			     fd_set *fd_w,
			     int *max_fd)
{
  FD_SET(host->fd, fd_r);
  FD_SET(host->fd, fd_w);
  *max_fd = host->fd;
}

static bool	read_input_available(t_host *host,
				     fd_set *fd_r,
				     fd_set *fd_w)
{
  if (FD_ISSET(host->fd, fd_r) && !read_server(host))
    return (false);
  else if (FD_ISSET(STDIN_FILENO, fd_r) && !read_user(host))
    return (false);
  else if (FD_ISSET(host->fd, fd_w) && !write_server(host))
    return (false);
  return (true);
}

bool		main_loop(t_host *host)
{
  int		max_fd;
  fd_set	fd_r;
  fd_set	fd_w;

  while (true)
    {
      FD_ZERO(&fd_r);
      FD_ZERO(&fd_w);
      FD_SET(STDIN_FILENO, &fd_r);
      max_fd = STDIN_FILENO;
      if (host->fd != -1)
	is_connected(host, &fd_r, &fd_w, &max_fd);
      if (select(max_fd + 1, &fd_r, &fd_w, NULL, NULL) == ERR_FUNC)
	return (error_handler(false, "select()", false));
      if (!read_input_available(host, &fd_r, &fd_w))
	return (false);
    }
  return (true);
}
