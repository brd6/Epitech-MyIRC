/*
** my_free_wordtab.c for my_free_wordtab in /home/bongol_b/Epitech-rendu/libmy
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Feb 21 18:52:03 2016 Berdrigue BONGOLO BETO
** Last update Thu Jun  1 19:11:35 2017 bongol_b
*/

#include <stdlib.h>

void		my_free_wordtab(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL || *tab == NULL)
    return ;
  while (tab && tab[i])
    free(tab[i++]);
  free(tab);
  tab = NULL;
}
