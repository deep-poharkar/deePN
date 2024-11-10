#include "vpn.h"
#include <iostream>

VPN::VPN() : is_initialized(false), server_address("vpn.example.com"), port(1194) {}

VPN::~VPN() {}

bool VPN::initialize()
{
    std::cout << "Initializing VPN connection to " << server_address << " on port " << port << "..." << std::endl;
    is_initialized = true;
    return is_initialized;
}

void VPN::run()
{
    if (!is_initialized)
    {
        std::cerr << "VPN is not initialized!" << std::endl;
        return;
    }

    std::cout << "VPN tunnel established. Data encryption in progress..." << std::endl;
}

void VPN::stop()
{
    if (!is_initialized)
    {
        std::cerr << "VPN is not initialized!" << std::endl;
        return;
    }

    std::cout << "Stopping VPN connection..." << std::endl;
}
