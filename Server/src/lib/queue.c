/*
** queue.c for queue in /home/bongol_b/Epitech-rendu/CPE_2015_Lemin/file_utils
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Apr 18 20:26:05 2016 Berdrigue BONGOLO BETO
** Last update Fri Jun  9 00:37:39 2017 bongol_b
*/

#include <stdlib.h>
#include "queue.h"

void		queue_free(t_queue *queue)
{
  t_list	*curr;
  t_list	*prev;

  if (queue == NULL)
    return ;
  curr = queue->head;
  while (curr != NULL)
    {
      prev = curr;
      free(prev->data);
      free(prev);
      curr = curr->next;
    }
  queue->head = NULL;
  queue->queue = NULL;
}

int		queue_enqueue(t_queue *queue, void *data)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (0);
  new->data = data;
  new->next = NULL;
  if (queue->head == NULL)
    {
      queue->head = new;
      queue->queue = queue->head;
    }
  else
    {
      queue->queue->next = new;
      queue->queue = new;
    }
  return (1);
}

void		*queue_dequeue(t_queue *queue)
{
  t_list	*curr;
  void		*data;

  if (queue_is_empty(queue) || queue == NULL)
    return (NULL);
  data = queue->head->data;
  curr = queue->head;
  queue->head = queue->head->next;
  free(curr);
  return (data);
}
