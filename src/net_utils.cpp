#include "net_utils.h"
#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>

namespace NetUtils
{

    std::string resolve_hostname(const std::string &hostname)
    {
        struct hostent *he = gethostbyname(hostname.c_str());
        if (he == nullptr)
        {
            std::cerr << "Error resolving hostname: " << hostname << std::endl;
            return "";
        }
        struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;
        return inet_ntoa(*addr_list[0]); // Return the first IP address
    }
}
