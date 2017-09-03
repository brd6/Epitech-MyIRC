/*
** get_next_line.h for get_next_line.h in get_next_line
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Dec 27 13:21:10 2015 berdrigue bongolo-beto
** Last update Thu Jun  8 22:25:56 2017 bruel_a
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef READ_SIZE
#  define READ_SIZE (2048)
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);
char	*get_next(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
