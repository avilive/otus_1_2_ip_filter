#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "ip_filter.h"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string& str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

//sort ip_pool in descending order
bool sortIp(const std::vector<std::string>& v1, const std::vector < std::string > & v2) {


    if (stoi(v1[0]) != stoi(v2[0]))
        return stoi(v1[0]) > stoi(v2[0]);
    else if (stoi(v1[1]) != stoi(v2[1]))
        return stoi(v1[1]) > stoi(v2[1]);
    else if (stoi(v1[2]) != stoi(v2[2]))
        return stoi(v1[2]) > stoi(v2[2]);
    else  
        return stoi(v1[3]) > stoi(v2[3]);
}

//print ip_pool
void printIp(const  std::vector<std::vector<std::string>>& v1) {

    for (auto ip = v1.cbegin(); ip != v1.cend(); ++ip)
    {
        for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
            if (ip_part == ip->cend() - 1)
            {
                std::cout << std::endl;
            }
        }
    
    }
};


void printIpFiltered(const  std::vector<std::vector<std::string> >& v1, const std::string& f1)
{
    for (auto ip = v1.cbegin(); ip != v1.cend(); ++ip)
    {
           
        for (auto ip_part = ip->cbegin(); (ip_part != ip->cend())&&(*(ip->begin())) == f1; ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }

            std::cout << *ip_part;

            if (ip_part == ip->cend() - 1)
            {
                std::cout << std::endl;
            }
        }
      
    }
}

void printIpFiltered(const  std::vector<std::vector<std::string> >& v1, const std::string& f1 ,const std::string& f2)
{
    for (auto ip = v1.cbegin(); ip != v1.cend(); ++ip)
    {

        for (auto ip_part = ip->cbegin(); (ip_part != ip->cend()) && (*(ip->begin())) == f1 && (*(ip->begin()+1)) == f2; ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
            if (ip_part == ip->cend() - 1)
            {
                std::cout << std::endl;
            }
        }
    }
}

void printIpFilteredAny(const  std::vector<std::vector<std::string> >& v1, const std::string& f1)
{
    for (auto ip = v1.cbegin(); ip != v1.cend(); ++ip)
    {
        if (std::find(ip->cbegin(), ip->cend(), f1) != ip->cend())
        {
            for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";
                }
                std::cout << *ip_part;
                if (ip_part == ip->cend() - 1)
                {
                    std::cout << std::endl;
                }
            }
        }
     }
}

