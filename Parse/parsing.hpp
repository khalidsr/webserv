/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:37:23 by sriyani           #+#    #+#             */
/*   Updated: 2023/06/19 17:12:12 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

#ifndef PARSING_HPP
#define PARSING_HPP

typedef struct s_location
{
    std::string root_location;
    std::string url_location;
    std::vector<std::string> location;
    std::vector<std::string> methods;
    std::vector<std::string> index;
    std::vector<std::string> cgi_pass;
    std::string uploads;
    std::string return_url;
    std::vector<std::string> retrun_urlll;
    int  num_url;
    int num_return;
    bool auto_index;
    int flag_auto;
    int location_flag;

} location;

typedef struct s_server
{
private:
public:
    int num_location;
    int ind_port;
    unsigned long max_client;
    int flag_max_client;
    std::vector<std::string> server;
    std::string server_name;
    std::string host;
    std::vector<std::string> error_page;
    std::vector<int> error_num;
    std::vector<int> lent_server;
    location **loc;
    int server_flag;
    int location_falg;
    int error_flag;
} t_server;

typedef struct s_parsing
{
private:
    // std::vector<std::string> server_name;
public:
    int num_serv;
    int pars_flag;
    int count_flag;
    std::vector<std::string> vec;
    t_server **serv;
    void copy_file(s_parsing *pars, std::string ptr);
    void check_key(s_parsing *pars);
    void check_server(s_parsing *pars, size_t len);
    void check_listen(t_server *pars, std::string str);
    void check_server_name(t_server *serv, std::string str);
    void check_error_pages(t_server *serv, std::string str);
    void check_max_client(t_server *serv, std::string str);
    void check_location(location *loc);
    std::string trim(const std::string &str);
    void check_port(s_parsing *pars);

} parsing;
bool whitespace(unsigned char c);
bool isWhitespace(unsigned char c);
int check_semi_colonne(std::string str);
int ft_len(std::string s, char c);

#endif