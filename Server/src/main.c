/*
** main.c for main in PSU_2016_myirc
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 23 14:00:13 2017 bruel_a
** Last update Sun Jun 11 19:14:32 2017 bongol_b
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "myirc.h"

t_irc		g_irc;

static void	sigint_handler(int sig)
{
  g_irc.should_stop = true;
  close(g_irc.server_fd);
  (void)sig;
}

int		main(int ac, char **av)
{
  g_irc.should_stop = false;
  signal(SIGINT, sigint_handler);
  signal(SIGTERM, sigint_handler);
  if (ac == 1)
    {
      dprintf(2, USAGE, av[0]);
      return (TEK_EXIT_FAILURE);
    }
  else if (strcmp(av[1], HELP) == 0)
    {
      dprintf(2, USAGE, av[0]);
      return (TEK_EXIT_SUCCESS);
    }
  if (!init_irc_server(av[1]) ||
      !listen_clients())
    return (TEK_EXIT_FAILURE);
  return (TEK_EXIT_SUCCESS);
}
