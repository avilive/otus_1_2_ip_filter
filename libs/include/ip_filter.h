// otus_1_2_ip_filter.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>

// TODO: Reference additional headers your program requires here.
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string& str, char d);

bool sortIp(const std::vector<std::string>& v1, const std::vector < std::string >& v2);

void printIp(const  std::vector<std::vector<std::string> >& v1);

void printIpFiltered(const  std::vector<std::vector<std::string> >& v1, const std::string& f1);

void printIpFiltered(const  std::vector<std::vector<std::string> >& v1, const std::string& f1, const std::string& f2);

void printIpFilteredAny(const  std::vector<std::vector<std::string> >& v1, const std::string& f1);
