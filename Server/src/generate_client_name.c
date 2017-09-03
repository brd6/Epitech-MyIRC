/*
** generate_client_name.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun 10 00:10:35 2017 bongol_b
** Last update Sat Jun 10 21:09:08 2017 bongol_b
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char		*generate_client_name()
{
  char		*name;

  name = NULL;
  srand(time(NULL));
  if (asprintf(&name, "Client%d", 100 + rand() % 82048) < 1)
    return (NULL);
  return (name);
}
