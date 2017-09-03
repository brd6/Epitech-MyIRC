/*
** get_next_line.c for get_next_line in /home/bruel_a/libbruel_a
**
** Made by bruel
** Login   <bruel_a@epitech.net>
**
** Started on  Mon Nov 21 11:34:14 2016 bruel
** Last update Wed May 31 10:49:35 2017 bruel_a
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myirc.h"
#include "get_next_line.h"

static bool	get_end_line(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    if (str[i++] == '\n')
      return (true);
  return (false);
}

char	*get_next(const int fd)
{
  char	*str;
  char	buff[READ_SIZE];
  int	i;

  if ((str = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  str[0] = '\0';
  while (get_end_line(str) == false)
    {
      memset(buff, '\0', READ_SIZE);
      if ((i = read(fd, buff, READ_SIZE)) <= 0)
	return (NULL);
      buff[i] = '\0';
      if ((str = realloc(str, strlen(str) + READ_SIZE + 1)) == NULL)
	return (NULL);
      strncat(str, buff, READ_SIZE);
    }
  return (str);
}
