/*
** error_handler.c for error_handler in PSU_2016_myirc
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Thu May 25 16:50:17 2017 bruel_a
** Last update Thu Jun  8 22:32:50 2017 bruel_a
*/

#include <stdio.h>
#include <stdbool.h>

int	error_handler(bool mode, const char *msg, int ret)
{
  if (!mode)
    perror(msg);
  else
    dprintf(2, "%s", msg);
  return (ret);
}
