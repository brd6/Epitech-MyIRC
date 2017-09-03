/*
** queue_init.c for queue_init in /home/bongol_b/CPE_2015_Lemin/src/file_utils
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Apr 18 20:07:18 2016 Berdrigue BONGOLO BETO
** Last update Fri Jun  9 00:44:19 2017 bongol_b
*/

#include <stddef.h>
#include "queue.h"

int		queue_init(t_queue *queue)
{
  queue->head = NULL;
  queue->queue = NULL;
  return (1);
}

int		queue_is_empty(t_queue *queue)
{
  return (queue->head == NULL);
}

void		*queue_get_head(t_queue *queue)
{
  return (!queue_is_empty(queue) ? queue->head->data : NULL);
}

void		*queue_get_end(t_queue *queue)
{
  return (!queue_is_empty(queue) ? queue->queue->data : NULL);
}
