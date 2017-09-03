/*
** queue.h for que in /home/bongol_b/Epitech-rendu/CPE_2015_Lemin/src/file_utils
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Apr 18 20:23:47 2016 Berdrigue BONGOLO BETO
** Last update Fri Jun  9 00:47:36 2017 bongol_b
*/

#ifndef QUEUE_H_
# define QUEUE_H_

# include "mylist.h"

typedef struct		s_queue
{
  t_list		*queue;
  t_list		*head;
}			t_queue;

int			queue_init(t_queue *queue);
int			queue_is_empty(t_queue *queue);
void			*queue_get_head(t_queue *queue);
void			*queue_get_end(t_queue *file);
void			queue_free(t_queue *queue);
int			queue_enqueue(t_queue *queue, void *data);
void			*queue_dequeue(t_queue *queue);

#endif /* !QUEUE_H_ */
