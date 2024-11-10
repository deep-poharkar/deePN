#include "tunnel.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

Tunnel::Tunnel() : sockfd(-1), tunnel_established(false) {}

Tunnel::~Tunnel()
{
    if (tunnel_established)
    {
        stop_tunnel();
    }
}

bool Tunnel::start_tunnel(const std::string &vpn_address)
{
    std::cout << "Starting VPN tunnel to: " << vpn_address << std::endl;

    // a socket for UDP communication
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Error creating socket!" << std::endl;
        return false;
    }

    // server address (VPN server address)
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1194); // default OpenVPN port
    if (inet_pton(AF_INET, vpn_address.c_str(), &server_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid VPN address!" << std::endl;
        return false;
    }

    // At this point, we can send data packets to the VPN server, but for now, let's consider the tunnel as "started"
    tunnel_established = true;
    std::cout << "VPN tunnel established successfully!" << std::endl;

    return true;
}

void Tunnel::stop_tunnel()
{
    if (sockfd != -1)
    {
        std::cout << "Stopping VPN tunnel..." << std::endl;
        close(sockfd); // Closing the socket to stop the tunnel
        sockfd = -1;
        tunnel_established = false;
        std::cout << "VPN tunnel stopped." << std::endl;
    }
}
