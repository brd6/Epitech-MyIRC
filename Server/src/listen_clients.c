/*
** listen_clients.c for listen_clients in PSU_2016_myirc
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Fri May 26 07:52:10 2017 bruel_a
** Last update Sun Jun 11 19:14:16 2017 bongol_b
*/

#include "myirc.h"

bool		listen_clients()
{
  init_client_socks();
  while (!g_irc.should_stop)
    {
      if (!handle_clients())
	{
	  g_irc.should_stop = 1;
	  return (false);
	}
    }
  return (true);
}
