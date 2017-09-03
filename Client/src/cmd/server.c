/*
** server.c for server in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 30 10:35:42 2017 bruel_a
** Last update Thu Jun  8 22:29:57 2017 bruel_a
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "myirc.h"

static char	*generate_user_name(void)
{
  char		*user_name;
  int		i;

  i = 0;
  if ((user_name = malloc(sizeof(char) * (USER_NAME_SIZE + 1))) == NULL)
    return (NULL);
  while (i < 5)
    {
      user_name[i] = (rand() % 25) + 97;
      ++i;
    }
  user_name[i] = '\0';
  return (user_name);
}

static bool	do_connexion(t_host *host, char *ip, int port)
{
  t_protoent	*protoent;
  t_sockaddr	addr;
  char		*str;
  char		*user_name;

  if ((protoent = getprotobyname(PROTOCOL_TYPE)) == NULL ||
      (addr.sin_addr.s_addr = inet_addr(ip)) == INADDR_NONE)
    return (error_handler(false, "inet_addr()", false));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if ((host->fd = socket(AF_INET, SOCK_STREAM, protoent->p_proto)) == ERR_FUNC)
    return (error_handler(false, "socket()", false));
  if (connect(host->fd, (struct sockaddr *)&addr, sizeof(addr)) == ERR_FUNC)
    {
      close(host->fd);
      host->fd = -1;
      asprintf(&str, ERR_CONNECT, ip, port);
      write(STDOUT_FILENO, str, strlen(str));
    }
  if ((user_name = generate_user_name()) == NULL)
    return (false);
  asprintf(&host->out, "%s%s%s %s %s", host->out, NICK,
	   USER, user_name, USER_CMD);
  return (true);
}

bool	server_cmd(t_host *host, char **cmd)
{
  char	**info;

  if (cmd[1] == NULL)
    write(STDERR_FILENO, ERR_NO_ARG, strlen(ERR_NO_ARG));
  else if (host->fd == -1)
    {
      if ((info = str_to_wordtab(cmd[1], ":")) == NULL)
	return (false);
      if (info[0] == NULL || strlen(cmd[1]) < 4)
	{
	  write(STDERR_FILENO, ERR_NO_ARG, strlen(ERR_NO_ARG));
	  return (true);
	}
      if (info[1] == NULL)
	{
	  info[1] = strdup("6667");
	  info[2] = NULL;
	}
      if (!do_connexion(host, info[0], atoi(info[1])))
	return (false);
      freetab(info);
    }
  else
    write(STDERR_FILENO, ERR_ALREADY_CO, strlen(ERR_ALREADY_CO));
  return (true);
}
