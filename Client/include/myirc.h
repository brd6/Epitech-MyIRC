/*
** myirc.h for myirc in PSU_2016_myirc/Client
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Mon May 29 16:54:52 2017 bruel_a
** Last update Wed Jun  7 09:03:49 2017 bruel_a
*/

#ifndef MYIRC_H_
# define MYIRC_H_

# include <stdbool.h>

# define BUFF_SIZE	1024
# define ERR_FUNC	-1
# define USER_NAME_SIZE	5

# define PROTOCOL_TYPE	"TCP"

# define ERR_CONNECT	"Error: Connexion fail to %s:%d\n"
# define ERR_NO_ARG	"Error: no arg passed.\n"
# define ERR_ALREADY_CO	"Error: already connected.\n"
# define ERR_NO_CO	"Error: You must be connected, use /server.\n"
# define ERR_NICK_INV	"Error: Not allowed, Use /accept_file $nickname\n"

# define NICK		"NICK Anon\r\n"
# define NICK_CMD	"NICK %s\r\n"
# define USERS_CMD	"USERS \r\n"
# define QUIT_CMD	"QUIT \r\n"
# define QUIT_CMD_MSG	"QUIT :%s\r\n"
# define PART_CMD	"PART #%s\r\n"
# define NAMES_CMD	"NAMES #%s\r\n"
# define LIST_CMD	"LIST #%s\r\n"
# define JOIN_CMD	"JOIN #%s\r\n"
# define FILE_ADD_CMD	"The file '%s' has been added.\n"
# define INVALID_CMD	"Error: Invalid command.\n"
# define MSG		"PRIVMSG"
# define LIST		"LIST \r\n"
# define ALL_PRIVMSG	"PRIVMSG %s :%s\r\n"
# define USER		"USER"
# define USER_CMD	"nobody unknown unknown :noname\r\n"

typedef struct protoent		t_protoent;
typedef struct sockaddr_in	t_sockaddr;

typedef struct	s_host
{
  int		fd;
  char		*in;
  char		*out;
  char		**users;
}		t_host;

typedef struct	s_irc_cmd
{
  const char	*str;
  bool		(*func)(t_host *, char **);
}		t_irc_cmd;

t_host		init_host(void);
bool		main_loop(t_host *);
void		host_out(t_host *);
void		freetab(char **);
int		tablen(char **);
char		**tabdup(char **);
char		*epur_str(char *, const char *);
int		error_handler(bool, const char *, int);
bool		read_user(t_host *);
bool		read_server(t_host *);
bool		write_server(t_host *);
char		**str_to_wordtab(char *, const char *);
bool		server_cmd(t_host *, char **);
bool		nick_cmd(t_host *, char **);
bool		exit_cmd(t_host *, char **);
bool		users_cmd(t_host *, char **);
bool		part_cmd(t_host *, char **);
bool		names_cmd(t_host *, char **);
bool		quit_cmd(t_host *, char **);
bool		list_cmd(t_host *, char **);
bool		join_cmd(t_host *, char **);
bool		msg_cmd(t_host *, char **);
bool		default_cmd(t_host *, char **);
char		**get_users(t_host *);
bool		accept_file_cmd(t_host *, char **);

#endif /* !MYIRC_H_ */
