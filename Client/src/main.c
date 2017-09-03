/*
** main.c for main in PSU_2016_myirc
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 23 14:00:53 2017 bruel_a
** Last update Wed Jun  7 09:02:14 2017 bruel_a
*/

#include <stdlib.h>
#include <time.h>
#include "myirc.h"

int		main(void)
{
  t_host	host;
  bool		ret;

  srand(time(NULL));
  host = init_host();
  ret = main_loop(&host);
  host_out(&host);
  return (ret == false ? 84 : EXIT_SUCCESS);
}
