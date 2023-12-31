/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:22:05 by root              #+#    #+#             */
/*   Updated: 2023/07/26 22:46:58 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_HPP
# define LIBRARY_HPP

/* Color ******************************************************************** */

# define RESET      "\033[0m"
# define BLACK      "\033[30m"      
# define RED        "\033[31m"     
# define GREEN      "\033[32m"      
# define YELLOW     "\033[33m"      
# define BLUE       "\033[34m"      
# define MAGENTA    "\033[35m"      
# define CYAN       "\033[36m"      
# define WHITE      "\033[37m"
# define PINK       "\033[38;5;206m"

# define BOLD       "\x02"

/* Define ******************************************************************* */

# define BUFFER_SIZE 1024

/* Others ******************************************************************* */

# define DELETING   "\x1b[1F\x1b[2K\r"


/* Includes ***************************************************************** */

# include <poll.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <fcntl.h>
# include <arpa/inet.h>
# include <errno.h>

# include <iostream>
# include <stdexcept>
# include <cstdlib>
# include <sstream>
# include <csignal>
# include <cstring>
# include <netdb.h>
# include <ctime>
# include <iomanip>
# include <algorithm>

# include <vector>
# include <list>
# include <map>
# include <string>

/* Includes.h *************************************************************** */

# include "Channel.hpp"
# include "Client.hpp"
# include "Utils.hpp"
# include "Command.hpp"

# include "Message.hpp"
# include "Server.hpp"

#endif
