/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:32:51 by mthiry            #+#    #+#             */
/*   Updated: 2023/07/17 15:29:57 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP
# include "library.hpp"

class Server;
class Channel;
class Client;

enum MessageType
{
    UNKNOW,
    PRIVMSG,
    NICK,
    USER,
    JOIN,
    PONG,
    MODE
};

class Command
{
    public:
        Command(const std::string &message);
        ~Command();

        /* Commands */
        static void                 welcomeMessages(Server &server, Client &client);
        static void                 privmsgMessages(Server *server, Client *src, std::string destNickname, std::string message);
        static void                 privmsgMessagesChannel(Server *server, Client *src, std::string destNickname, std::string message);
        static void                 privmsgMessagesUser(Server *server, Client *src, std::string destNickname, std::string message);
        static void                 nickMessages(Server &server, Client *client, std::string newNickname);

        /* Messages Utils */
        static Channel*             checkForChannel(Server &server, std::string nickname);
        static Client*              checkForUser(Server &server, std::string nickname);

        /* Nick Utils */
        static bool                 nicknameIsAlreadyInUse(const Server &server, const std::string &newNickname);
        static bool                 isNotRightNickname(const Server &server, const std::string &newNickname);

        /* Setters */
        void                        setMessage(const std::string &message);
        void                        setType();
        void                        setArgs();

        /* Getters */
        std::string                 getMessage();
        MessageType                 getType();
        std::vector<std::string>    getArgs();
        
    private:
        std::string                 message;
        MessageType                 type;
        std::vector<std::string>    args;
};

#endif