/*
** server.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Mon Jun  5 15:13:40 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"

static char	*create_msg(char **cmd)
{
  char		*msg;
  int		i;

  i = 1;
  asprintf(&msg, "%s", cmd[0]);
  while (cmd[i] != NULL)
    asprintf(&msg, "%s %s", msg, cmd[i++]);
  return (msg);
}

static char	**delete_new_lines(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      tab[i][strlen(tab[i]) - 1] = '\0';
      ++i;
    }
  return (tab);
}

static void	send_msg(const t_host *host,
			 const char *msg,
			 const char *user)
{
  char		*str;

  asprintf(&str, ALL_PRIVMSG, msg, user);
  write(host->fd, str, strlen(str));
  free(str);
}

bool	default_cmd(t_host *host, char **cmd)
{
  char	**users;
  char	*msg;
  int	i;

  i = 0;
  if (cmd[0] != NULL && cmd[0][0] != '\0')
    {
      if ((users = get_users(host)) == NULL ||
	  (msg = create_msg(cmd)) == NULL ||
	  (users = delete_new_lines(users)) == NULL)
	return (NULL);
      while (users[i] != NULL)
	send_msg(host, msg, users[i++]);
      freetab(users);
      free(msg);
    }
  return (true);
}
