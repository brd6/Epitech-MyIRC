/*
** irc_rpl.h for myirc in /home/bongol_b/Epitech-rendu/TEK2/B4 - Systeme Unix - Réseau/PSU_2016_myirc/Server/include
**
** Made by bongol_b
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jun  1 15:14:27 2017 bongol_b
** Last update Fri Jun  9 21:55:30 2017 bongol_b
*/

#ifndef IRC_RPL_H_
# define IRC_RPL_H_

# define RPL_WELCOME		"001 :Welcome to the Internet Relay Network \
%s!%s@%s"
# define ERR_NONICKNAMEGIVEN	"431 :No nickname given"
# define ERR_NICKCOLLISION	"436 %s :Nickname collision KILL"
# define ERR_NICKNAMEINUSE	"433 %s :Nickname is already in use"
# define ERR_NEEDMOREPARAMS	"461 %s :Not enough parameters"
# define ERR_ALREADYREGISTRED	"462 :You may not reregister"
# define ERR_NOLOGIN		"444 %s :User not logged in"
# define ERR_NOSUCHNICK		"401 %s :No such nick/channel"
# define ERR_UNKNOWNCOMMAND	"421 %s :Unknown command"
# define ERR_NOTREGISTERED	"451 :You have not registered"
# define ERR_USERONCHANNEL	"443 %s %s :is already on channel"
# define RPL_TOPIC		"332 %s :%s"
# define RPL_NOTOPIC		"331 %s :No topic is set"
# define RPL_NAMREPLY		"353 %s :%s"
# define RPL_ENDOFNAMES		"366 %s :End of /NAMES list"
# define ERR_NOSUCHCHANNEL	"403 %s :No such channel"
# define ERR_NOTONCHANNEL	"442 %s :You're not on that channel"
# define RPL_LISTSTART		"321 Channel :Users Name"
# define RPL_LIST		"322 %s %s :%s"
# define RPL_LISTEND		"323 :End of /LIST"
# define ERR_ERRONEUSNICKNAME	"432 %s :Erroneus nickname"
# define ERR_BADCHANMASK	"476 %s :bad channel name"
# define ERR_PASSWDMISMATCH	"464 :Password incorrect"
# define ERR_NOORIGIN		"409 :No origin specified"
# define ERR_NOSUCHSERVER	"402 %s :No such server"
# define RPL_USERSSTART		"392 :UserID Terminal Host"
# define RPL_USERS		"393 :%s"
# define RPL_ENDOFUSERS		"394 :End of users"
# define RPL_NOUSERS		"395 :Nobody logged in"
# define ERR_NORECIPIENT	"411 :No recipient given (%s)"
# define ERR_NOTEXTTOSEND	"412 :No text to send"
# define ERR_CANNOTSENDTOCHAN	"404 %s :Cannot send to channel"

#endif /* !IRC_RPL_H_ */
