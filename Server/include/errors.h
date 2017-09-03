/*
** errors.h for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/include
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Wed May 31 01:31:38 2017 bongol_b
** Last update Fri Jun  9 21:21:00 2017 bongol_b
*/

#ifndef ERRORS_H_
# define ERRORS_H_

# define ERR_INIT_SOCKET	"Error: Unable to initialize the socket\n"
# define ERR_INIT_SOCKET_BIND	"Error: Unable to bind the socket\n"
# define ERR_INIT_SOCKET_LISTEN	"Error: Unable to listen the socket\n"
# define ERR_SOCKET_ACCEPT	"Error: Unable to accept client\n"
# define ERR_SOCKET_OPT		"Error: Unable to set a socket option\n"
# define ERR_WRITE		"Error: An error occured during write process\n"
# define ERR_READ		"Error: An error occured during read process\n"
# define ERR_SEND_MSG		"Error: Unable to send a message throw socket\n"

# define TOO_MUCH_FD		"Error: Too much file descriptors set.\n"
# define ERR_WHILE_LIST		"Error: impossible to list fd(s)\n"

# define ERR_ADD_CLIENT		"Error: Unable to add a new client\n"

#endif /* !ERRORS_H_ */
