/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:32:31 by mthiry            #+#    #+#             */
/*   Updated: 2023/07/13 00:50:07 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Command.hpp"

Command::Command(const std::string &message)
{
    this->setMessage(message);
    this->setType();
    this->setArgs();
}
Command::~Command() {}

/* Commands */
void Command::welcomeMessages(Server &server, Client &client)
{
    std::string welcome001 = ":" + server.getName() + " 001 " + client.getNickname() \
        + " :Welcome to " + server.getName() + ", " + client.getNickname() + "!" + client.getUsername() + "@" + client.getHostname() + "\r\n";
    std::string welcome002 = ":" + server.getName() + " 002 " + client.getNickname() \
        + " :Your host is " + server.getName() + ", running version 0.1" + "\r\n";
    std::string welcome003 = ":" + server.getName() + " 003 " + client.getNickname() \
        + " :..." + "\r\n";
    std::string welcome004 = ":" + server.getName() + " 004 " + client.getNickname() \
        + " :..." + "\r\n";
        
    Utils::debug_message("Send welcome message to: " + client.getUsername());
    client.sendToFD(welcome001);
    client.sendToFD(welcome002);
    // client.sendToFD(welcome003);
    // client.sendToFD(welcome004);
}

void Command::nickMessages(Server &server, Client *client, std::string newNickname)
{
    std::string nick001 = ":" + server.getName() + " 001 " + newNickname \
        + " :You're now known as " + newNickname + "\r\n";
    std::string nick431 = ":" + server.getName() + " 431 *" \
        + " :No nickname given" + "\r\n";
    std::string nick432 = ":" + server.getName() + " 432 * " + newNickname \
        + " :Erroneous nickname" + "\r\n";
    std::string nick433 = ":" + server.getName() + " 433 * " + newNickname \
        + " :Nickname is already in use" + "\r\n";
    
    if (newNickname.empty())
    {
        Utils::debug_message("Not enough arguments on NICK from: " + client->getUsername());
        client->sendToFD(nick431);
    }
    else if (Command::nicknameIsAlreadyInUse(server, newNickname))
    {
        Utils::debug_message(client->getUsername() + " tried to change his nickname to something that already exists");
        client->sendToFD(nick433);
    }
    else
    {
        Utils::debug_message("Change " + client->getUsername() + " nickname to: " + newNickname);
        client->setNickname(newNickname);
        client->sendToFD(nick001);
    }

    /* Can be added later */
    // else if ()
    // {
    //     client.sendToFD(nick432);
    // }    
}

void Command::msgMessages(Server &server, Client *src, Client *dest, std::string message)
{
    (void)server;
    std::string msg001_1 = ":" + src->getNickname() + "!" + src->getUsername() + "@" + src->getHostname();
    std::string msg001_2 = " RPL_PRIVMSG " + dest->getNickname() + " :" + message + "\r\n";
    std::string msg001 = msg001_1 + msg001_2;

    src->sendToFD(msg001);
    dest->sendToFD(msg001);

    // :pseudonyme!ident@hôte RPL_PRIVMSG destinataire :message
}

/* Nick Utils */
bool Command::nicknameIsAlreadyInUse(Server &server, std::string newNickname)
{
    std::map<int, Client*>              clients;
    std::map<int, Client*>::iterator    it;

    clients = server.getClientsList();
    it = clients.begin();
    while (it != clients.end())
    {
        if (it->second->getNickname() == newNickname)
            return (true);
        ++it;
    }
    return (false);
}

/* Setters */
void Command::setMessage(const std::string &message) { this->message = message; }

void Command::setType()
{
    std::string type;

    type = this->message.substr(0, this->message.find(' '));
    this->message.erase(0, this->message.find(' ') + 1);
    if (type == "PRIVMSG")
        this->type = PRIVMSG;
    else if (type == "NICK")
        this->type = NICK;
    else if (type == "USER")
        this->type = USER;
    else if (type == "JOIN")
        this->type = JOIN;
    else if (type == "PONG")
        this->type = PONG;
    else if (type == "MODE")
        this->type = MODE;
    else
        this->type = UNKNOW;
}

void Command::setArgs()
{
    std::size_t pos;

    pos = this->message.find(' ');
    if (pos != std::string::npos)
    {
        std::string arg = this->message.substr(0, pos);
        this->args.push_back(arg);
        this->message.erase(0, pos + 1);
    }
    if (!this->message.empty())
    {
        this->message = this->message.substr(0, this->message.find('\r'));
        pos = this->message.find(':');
        if (pos != std::string::npos)
            this->message.erase(0, pos + 1);
        this->args.push_back(this->message);
    }
}

/* Getters */
std::string Command::getMessage() { return (this->message); }
MessageType Command::getType() { return (this->type); }
std::vector<std::string> Command::getArgs() { return (this->args); }