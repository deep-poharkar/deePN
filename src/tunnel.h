#ifndef TUNNEL_H
#define TUNNEL_H

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

class Tunnel
{
public:
    Tunnel();
    ~Tunnel();

    bool start_tunnel(const std::string &vpn_address);
    void stop_tunnel();

private:
    int sockfd;
    struct sockaddr_in server_addr;
    bool tunnel_established;
};

#endif // TUNNEL_H
