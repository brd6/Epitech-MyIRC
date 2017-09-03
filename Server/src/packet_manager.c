/*
** packet_manager.c for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/src
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May 31 01:16:49 2017 bongol_b
** Last update Sun Jun 11 19:25:17 2017 bongol_b
*/

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "myirc.h"
#include "errors.h"
#include "get_next_line.h"

int		packet_send_buffered(int sock)
{
  t_client	*client;
  char		*data;

  if ((client = get_client_by_sockfd(sock)) == NULL)
    return (0);
  if ((data = queue_dequeue(&client->packets)) == NULL)
    return (0);
  return (packet_send_raw(sock, data, strlen(data)));
}

int		packet_send(int sock, char *str)
{
  t_client	*client;
  char		*data;

  data = NULL;
  if (asprintf(&data, "%s\r\n", str) < 1 || data == NULL)
    return (0);
  if ((client = get_client_by_sockfd(sock)) == NULL)
    return (packet_send_raw(sock, data, strlen(data)));
  return (queue_enqueue(&client->packets, data));
}

int		packet_send_raw(int sock, char *buff, int size)
{
  int		i;

  if ((i = write(sock, buff, size)) == -1)
    return (dprintf(2, ERR_WRITE), 0);
  return (1);
}

int		packet_send_varg(int sock, const char *format, ...)
{
  char		buff[BUFF_SIZE];
  va_list	ap;

  va_start(ap, format);
  vsprintf(buff, format, ap);
  va_end(ap);
  return (packet_send(sock, buff));
}

char		*packet_receive(int sock)
{
  char		*buff;
  int		i;

  if ((buff = get_next_line(sock)) == NULL)
    {
      cmd_quit(sock, NULL);
      return (NULL);
    }
  i = strlen(buff);
  if (i == 0)
    return (NULL);
  if (i > 1 && strncmp(&buff[i - 1], "\r", 1) == 0)
    buff[i - 1] = 0;
  return (buff);
}
