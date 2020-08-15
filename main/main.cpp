#include "ip_filter.h"
#include <iostream>
#include <algorithm> // for sort() 
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
    try
    {
        std::vector<std::vector<std::string> > ip_pool;

/*        for (std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }*/

        {// read from file for testing
            std::string line;
            std::ifstream myfile("C:\\Users\\avili\\Documents\\OTUS CPP\\1\\otus_1_2_ip_filter\\main\\ip_filter.tsv");
            if (myfile.is_open())
            {
                while (std::getline(myfile, line))
                {
                    std::vector<std::string> v = split(line, '\t');
                    ip_pool.push_back(split(v.at(0), '.'));
                }
                myfile.close();
            }
            else
            {
                std::cout << "Error opening file" << std::endl;
            }
        }

        //reverse lexicographically sort
        sort(ip_pool.begin(), ip_pool.end(), sortIp);
        printIp(ip_pool);
        printIpFiltered(ip_pool, "1");
        printIpFiltered(ip_pool, "46", "70");
        printIpFilteredAny(ip_pool, "46");

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)
        // std::vector<std::vector<std::string> > ip = filter(1);


        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
