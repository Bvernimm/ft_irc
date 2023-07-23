/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:46:41 by mthiry            #+#    #+#             */
/*   Updated: 2023/07/23 13:22:57 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP
# include "library.hpp"

class Channel;
class Message;
class Server;

class Message
{
    public:
        /* Authentification and connection */
        static std::string  connection(const std::string &serverName, const std::string &clientNickname);
        static std::string  welcome(const std::string &serverName, const std::string &clientNickname, const std::string &clientUsername, const std::string &clientHostname, const std::string &date);

        /* Commands */
        static std::string  join(const std::string &clientNickname, const std::string &clientUsername, const std::string &clientHostname, const std::string &channelName);
        static std::string  part(const std::string &clientNickname, const std::string &clientUsername, const std::string &clientHostname, const std::string &channelName, const std::string &message);
        static std::string  privmsg(const std::string &srcName, const std::string &destName, const std::string &message);
        static std::string  nick(const std::string &serverName, const std::string &newNickname);
        static std::string  kick(const std::string &srcName, const std::string &destName, const std::string &channelName, const std::string &message);
        static std::string  ping(const std::string &serverName);
        static std::string  pong(const std::string &serverName);

        /* RPL */
        static std::string  rpl_umodeis_221(const std::string &serverName, const std::string &nickname, const std::string &modes);
        static std::string  rpl_channelmodesis_324(const std::string &serverName, const std::string &clientNickname, const std::string &channelName, const std::string &modes);
        static std::string  rpl_notopic_331(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  rpl_topic_332(const std::string &serverName, const std::string &clientNickname, const std::string &channelName, const std::string &topic);
        static std::string  rpl_inviting_341(const std::string &serverName, const std::string &srcNickname, const std::string &channelName, const std::string &destNickname);
        static std::string  rpl_namreplay_353(const std::string &serverName, const std::string &clientNickname, const std::string &channelName, const Channel &channel);
        static std::string  rpl_endofnames_366(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);

        /* Errors */
        static std::string  err_nosuchnick_401(const std::string &serverName, const std::string &nickname);
        static std::string  err_nosuchserver_402(const std::string &serverName, const std::string &nickname, const std::string &destName);
        static std::string  err_nosuchchannel_403(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  err_cannotsendtochan_404(const std::string &serverName, const std::string &nickname);
        static std::string  err_nonicknamegiven_431(const std::string &serverName);
        static std::string  err_erroneusnickname_432(const std::string &serverName, const std::string &nickname);
        static std::string  err_nicknameinuse_433(const std::string &serverName, const std::string &nickname);
        static std::string  err_usernotinchannel_441(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  err_notonchannel_442(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  err_useronchannel_443(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  err_notregistered_451(const std::string &serverName, const std::string &nickname);
        static std::string  err_alreadyregistered_462(const std::string &serverName, const std::string &nickname);
        static std::string  err_passwdmismatch_464(const std::string &serverName, const std::string &nickname);
        static std::string  err_channelisfull_471(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  err_inviteonlychan_473(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  err_badchannelkey_475(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  err_chanoprivsneeded_482(const std::string &serverName, const std::string &clientNickname, const std::string &channelName);
        static std::string  err_umodeunknowflag_501(const std::string &serverName, const std::string &nickname);
        static std::string  err_usersdontmatch_502(const std::string &serverName, const std::string &nickname);
};

#endif