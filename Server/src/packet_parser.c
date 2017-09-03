/*
** packet_parser.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May 31 11:12:39 2017 bongol_b
** Last update Wed Jun 14 11:32:16 2017 bongol_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"
#include "my.h"

static char	*parse_msg(const char *str, int *next_idx, int is_params)
{
  char		*msg;
  int		i;
  int		j;

  if (str == NULL)
    return (NULL);
  i = *next_idx;
  i += skip_space(&str[i]);
  j = 0;
  if ((msg = malloc(sizeof(*msg) * (strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] &&
	 (is_params || (str[i] != PACKET_MSG_SEPARATORS[0] &&
			 str[i] != PACKET_MSG_SEPARATORS[1])))
    msg[j++] = str[i++];
  if (j == 0)
    return (free(msg), NULL);
  msg[j] = 0;
  *next_idx = i;
  return (msg);
}

static char	*parse_msg_prefix(const char *str, int *next_idx)
{
  int		i;

  i = skip_space(str);
  *next_idx = i;
  if (str[i] != PREFIX_START_CHAR)
    return (NULL);
  *next_idx += 1;
  return (parse_msg(str, next_idx, 0));
}

static int	parse_message(const char *str, t_message *msg)
{
  int		i;

  i = 0;
  msg->prefix = parse_msg_prefix(str, &i);
  msg->command = parse_msg(str, &i, 0);
  msg->params = parse_msg(str, &i, 1);
  return (1);
}

char		*extract_first_param(const char *params)
{
  int		i;

  i = 0;
  return (parse_msg(params, &i, 0));
}

t_message	**packet_parser(int sock)
{
  char		buff[BUFF_SIZE];
  char		**args;
  int		i;
  t_message	**msg;
  int		args_len;

  if ((i = read(sock, buff, BUFF_SIZE)) <= 0)
    return (cmd_quit(sock, NULL), NULL);
  buff[i] = 0;
  if (i == 1 || buff[i] == '\n' ||
      (args = my_str_split(buff, "\n\r")) == NULL || args[0] == NULL)
    return (NULL);
  args_len = my_wordtab_count((const char **)args);
  if ((msg = malloc(sizeof(*msg) * (args_len + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < args_len)
    {
      if ((msg[i] = malloc(sizeof(**msg))) == NULL)
	return (NULL);
      parse_message(args[i], msg[i]);
      i++;
    }
  msg[i] = NULL;
  return (msg);
}
