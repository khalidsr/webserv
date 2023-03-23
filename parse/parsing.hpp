/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:26:22 by mbadaoui          #+#    #+#             */
/*   Updated: 2023/03/23 16:03:27 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef PARSING_HPP
# define PARSING_HPP

struct parsing
{
    int ind_port;
    int ind_host;
    int error_pages;
    int limit_body;
    
    
    std::string server_name;
    
};


#endif