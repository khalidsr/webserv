/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:16:50 by mbadaoui          #+#    #+#             */
/*   Updated: 2023/05/28 10:55:44 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "../Server/Server.hpp"
#include "../utils/utils.hpp"
#include "../parse/parsing.hpp"
#include "../CGI/cgi.hpp"
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <unistd.h>
#include <cmath>

#define DIRECTORY 5
#define FILE 4
#define ERROR -1

class Request
{

private:
    Server                              _server;
    s_parsing                           *_parse;
    int                                 _http_status;
    int                                 _file_directory_check;
    int                                 _server_index;
    int                                 _location_index;
    int                                 _content_length;
    int                                 _read_fd;
    int                                 _chunked_content_value;
    int                                 _content_actual_size;
    int                                 _final_file_size;
    int                                 _size_of_read;
    int                                 _fd_file;
    int                                 _check_cgi;
    int                                 _cgi_child_process;
    std::string                         _cgi_content_header;
    CGI                                 _cgi_helper;
    std::string                         _cgi_ext;
    std::vector<std::string>            _file_name_path;
    std::vector<std::string>            _list_files_directories;
    std::string                         _directory_to_upload_in;
    std::string                         _buffer;
    std::string                         _current_directory;
    std::string                         _requested_file_path;
    std::string                         _available_file_path;
    std::string                         _directory_path;
    std::string                         _first_liner_header;
    std::string                         _method;
    std::string                         _path;
    std::map<std::string, std::string>  _arguments;
    std::string                         _protocol;
    std::string                         _body;
    std::map<std::string, std::string>  _header;
    std::map<std::string, std::string>  _response_final;
    std::string                         _response_body_as_string;
    std::map<std::string, std::string>  _cookie;

public:
  Request();
  ~Request();

  void clear_request_class();
  int ParseRequest(char *request_message);
  int UseMethod();
  int FirstLinerRequest(char *request_message);
  int HeaderRequest(char *request_message);
  void ft_http_code();
  void ft_mime_type();
  int ft_http_status(int value);
  int check_method_protocol();
  int is_request_well_formed(char *request_message);
  int is_body_size_good(char *request_message);
  int get_matched_location_for_request_uri();
  int is_location_have_redirection();
  int is_method_allowed_in_location();
  int GET_method();
  int get_request_resource();
  int get_request_resource_for_delete();
  int get_resource_type();
  int if_location_has_cgi();
  int POST_method();
  int DELETE_method();

  int Is_directory();
  void build_autoindex_page();
  int Is_directory_for_DELETE();
  int Is_file_for_DELETE();
  int is_uri_has_backslash_in_end();
  int is_dir_has_index_files();
  bool get_auto_index();
  int delete_all_folder_content(std::string, int);
  int has_write_access_on_folder();

  void get_all_subdirectories(std::string folder_name);

  void post_transfer_encoding();

  int   Is_file();

  // get which location
  int   get_location_index();
  // function to check in the header
  int   is_available(std::string, std::string);
  // function to check url for a character not allowed
  int   url_characters_checker();
  void  print_parse_vector();
  std::string remove_space(std::string tmp);
  // get the file_name_path value
  void  reform_requestPath_locationPath();
  std::string read_file(std::string);
  void  build_date();
  void  add_zero(int timer);
  int   check_for_arguments_in_path(std::string path);
  int   read_body_request();

  /*Response functions*/
  void  build_response();

  /* POST */
  int   upload_post_request();
  bool  location_support_upload();
  int   If_is_directory();
  bool  is_location_has_cgi();
  int   request_run_cgi();
  int   If_is_file();
  int   string_to_decimal(std::string);
  unsigned long hex_to_dec(std::string hex);

  std::map<int, std::string>          http_code;
  std::map<std::string, std::string>  mime_type;
  std::vector<std::string>            allowed_methods;
  bool  finished;
  bool  read_again;
  int   send_size;
  int   send_again;
  std::string Response;

  std::string getMethod() const;
  std::string getPath() const;
  std::string getProtocol() const;
  std::map<std::string, std::string> getHeader() const;
  std::string getResponse();
  std::string getAvailableFilePath() const;
  std::string get_server_buffer() const;
  int   getFile_size() const;
  int   getHttpStatus() const;
  int   get_cgi_helper() const;
  void  set_cgi_helper(int val);
  void  setParse(s_parsing *);
  void  setServer_index(int index);
  void  set_read_fd(int);
  void  setServer(Server);
  void  set_cgi_ext(std::string ext);
  int   get_cgi_child_process() const;
  void  set_cgi_child_process(int);
  std::string get_cgi_ext() const;
  std::string const &getBody() const;
  void  set_response_as_body(std::string);
  void  set_content_type(std::string);
  void  set_content_length(int size_content);
  void  set_cgi_content_header(std::string);
};

#endif
