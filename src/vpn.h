#ifndef VPN_H
#define VPN_H

#include <string>

class VPN
{
public:
    VPN();
    ~VPN();

    bool initialize();
    void run(); // connect and maintain tunnel
    void stop();

private:
    bool is_initialized; // check if initialized
    std::string server_address;
    int port;
};

#endif // VPN_H
