/*
** server.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Wed Jun  7 09:16:21 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "get_next_line.h"

static char	**extract_users_from_answer(char *resp)
{
  char		**users;
  char		**cut_answer;
  char		**words;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((users = malloc(sizeof(char *) * (strlen(resp) + 1))) == NULL ||
      (cut_answer = str_to_wordtab(resp, "\n")) == NULL)
    return (NULL);
  while (cut_answer[i] != NULL)
    {
      if ((words = str_to_wordtab(cut_answer[i], ":\n")) == NULL)
	return (NULL);
      if (words[0] != NULL && strcmp(words[0], "393 ") == 0 &&
	  words[1] != NULL)
	users[j++] = strdup(words[1]);
      freetab(words);
      ++i;
    }
  freetab(cut_answer);
  users[j] = NULL;
  return (users);
}

char	**get_users(t_host *host)
{
  char	*resp;
  char	**users;

  if (host->fd == -1)
    write(STDERR_FILENO, ERR_NO_CO, strlen(ERR_NO_CO));
  else
    write(host->fd, USERS_CMD, strlen(USERS_CMD));
  if ((resp = get_next(host->fd)) == NULL ||
      (users = extract_users_from_answer(resp)) == NULL)
    return (NULL);
  free(resp);
  return (users);
}

bool	users_cmd(t_host *host, char **cmd)
{
  (void)cmd;
  if (host->fd == -1)
    write(STDERR_FILENO, ERR_NO_CO, strlen(ERR_NO_CO));
  else
    write(host->fd, USERS_CMD, strlen(USERS_CMD));
  return (true);
}
