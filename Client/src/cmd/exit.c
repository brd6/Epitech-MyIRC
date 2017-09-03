/*
** exit.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Wed May 31 12:16:03 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"

bool	exit_cmd(t_host *host, char **cmd)
{
  host_out(host);
  freetab(cmd);
  exit(EXIT_SUCCESS);
  return (true);
}
