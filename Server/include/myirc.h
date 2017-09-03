/*
** myirc.h for myirc in PSU_2016_myirc/Server
**
** Made by bruel_a
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Tue May 23 14:16:17 2017 bruel_a
** Last update Sun Jun 11 19:03:57 2017 bongol_b
*/

#ifndef MYIRC_H_
# define MYIRC_H_

# include <sys/param.h>
# include <stdbool.h>
# include "mylist.h"
# include "queue.h"

# define USAGE	"USAGE: %s port\n"
# define HELP	"--help"

# define TEK_EXIT_FAILURE	84
# define TEK_EXIT_SUCCESS	0

# define MIN_PORT	0
# define MAX_PORT	65536
# define BACKLOG	42
# define FD_MAX		255
# define PROTOCOL_TYPE	"TCP"
# define UNKNOW_CHANNEL	-1
# define UNKNOW_CMD_IDX	-1
# define ERR_FUNC	-1
# define BUFF_SIZE	1024

# define MAX_CLIENT_SOCK	FD_SETSIZE

# define CHANNEL_NAME_MAX_LEN		200
# define CHANNEL_NAME_FIRST_CHAR	"&#"
# define CHANNEL_NAME_FORBIDEEN_CHARS	" \a,\t"

# define NICKNAME_MAX_LEN	9

# define PREFIX_START_CHAR	':'
# define PACKET_MSG_SEPARATORS	" \t"

# define CHANNEL_LOCAL_SYMBOL	'&'
# define CHANNEL_NETWORK_SYMBOL	'#'

# define NOT_LOGIN_IN_PROGRESS	0
# define WITH_LOGIN_IN_PROGRESS	1

typedef struct protoent		t_protoent;
typedef struct sockaddr_in	t_sockaddr;

typedef struct	s_message
{
  char		*prefix;
  char		*command;
  char		*params;
}		t_message;

typedef enum	e_fd_type
  {
    SERVER,
    WAITING,
    CLIENT,
    FREE
  }		t_fd_type;

typedef enum	e_client_state
  {
    UNAUTHENTICATED,
    LOGIN_IN_PROGRESS,
    AUTHENTIFICATED
  }		t_client_state;

typedef struct		s_channel
{
  char			*name;
  char			*subject;
  int			nb_client;
  t_list		*clients;
}			t_channel;

typedef struct		s_client
{
  int			sock_fd;
  char			*nickname;
  char			*realname;
  char			*username;
  t_client_state	state;
  char			*password;
  t_queue		packets;
}			t_client;

typedef struct	s_cmd
{
  char		*command;
  int		(*execute)(int sock_fd, t_message *msg);
}		t_cmd;

typedef struct	s_irc
{
  int		port;
  t_fd_type	type[MAX_CLIENT_SOCK];
  t_list	*clients;
  t_list	*channels;
  bool		should_stop;
  int		server_fd;
}		t_irc;

extern t_irc	g_irc;

int	error_handler(bool, const char *, int);
bool	init_irc_server(char *);
bool	irc_accept(int);
bool	listen_clients();
bool	irc_read(int);
bool	irc_write(int);
bool	close_fd(int);

int	packet_send(int sock, char *buff);
int	packet_send_raw(int sock, char *buff, int size);
char	*packet_receive(int sock);
int	packet_send_varg(int sock, const char *format, ...);
int	packet_send_buffered(int sock);

int	get_cmd(const char *cmd_name, t_cmd *cmd);
int	is_auth_cmd_allowed(const char *cmd);

int	cmd_pass(int sock, t_message *msg);
int	cmd_nick(int sock, t_message *msg);
int	cmd_user(int sock, t_message *msg);
int	cmd_quit(int sock, t_message *msg);
int	cmd_pong(int sock, t_message *msg);
int	cmd_join(int sock, t_message *msg);
int	cmd_names(int sock, t_message *msg);
int	cmd_part(int sock, t_message *msg);
int	cmd_list(int sock, t_message *msg);
int	cmd_topic(int sock, t_message *msg);
int	cmd_ping(int sock, t_message *msg);
int	cmd_users(int sock, t_message *msg);
int	cmd_privmsg(int sock, t_message *msg);

int	send_message_to_channel(int sock, char *name, t_message *msg);

t_message	**packet_parser(int sock);
char		*extract_first_param(const char *params);
char		*extract_second_prefix(const char *params);
char		**separe_param_and_second_prefix(const char *params);

t_client	*client_create_helper(int sock_fd,
				      const char *nickname,
				      t_client_state state);
int		add_client(t_client *client);
t_client	*get_client_by_sockfd(int sockfd);
t_client	*get_client_by_sockfd_check(int sockfd);
t_client	*get_client_by_nickname(const char *nickname);
t_client	*get_client_by_nickname_check(const char *nickname);
t_client	*get_client_by_username(const char *username);
t_client	*get_client_by_username_check(const char *username);
int		is_client_logged(int sock);
void		logout_client(t_client *client);
int		remove_client(t_client *client);

t_channel	*channel_create_helper(const char *name,
				       const char *subject);
int		add_channel(t_channel *channel);
t_channel	*get_channel_by_name(const char *name);
t_channel	*get_or_create_channel(const char *name);
int		add_client_in_channel(t_client *client, t_channel *channel);
int		is_client_in_channel(t_client *client, t_channel *channel);
int		remove_client_in_channel(t_client *client, t_channel *channel);

void		client_debug(t_client const *client);

int		try_authentificate_client(t_client *client);

int		skip_space(const char *str);

int		client_cmp_by_sockfd(t_client *client, int* sock_fd);
int		client_cmp_by_nickname(t_client *client, char *nickname);
int		client_cmp_by_username(t_client *client, char *username);
int		client_cmp_by_nickname_check(t_client *client, char *nickname);
int		client_cmp_by_username_check(t_client *client, char *username);
int		client_cmp_by_sockfd_check(t_client *client, int* sock_fd);

int		channel_cmp_by_name(t_channel *channel, char *name);

void		to_uppercase_string(char *s);

int		handle_clients();
void		close_client_connection(int sock);
int		answer_client_commands(int sock);
int		read_client_commands(int sock);
void		init_select_clients(fd_set *readfds,
				    fd_set *writefds,
				    int *max_fd);
void		init_client_socks();

char		*generate_client_name();

#endif /* !MYIRC_H_ */
