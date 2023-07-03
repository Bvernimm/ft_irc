/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:43:52 by root              #+#    #+#             */
/*   Updated: 2023/07/03 22:41:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    try
    {
        if (argc < 3)
            throw (std::runtime_error("Not enough arguments!"));
        else if (argc > 3)
            throw (std::runtime_error("Too many arguments!"));
        
        Server  run(argv[1], argv[2]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "[ERROR] : " << e.what() << std::endl;
        return (1);
    }
    return (0);
}