#include <iostream>
#include "vpn.h"

int main()
{
    std::cout << "Starting deePN VPN..." << std::endl;

    VPN vpn;
    if (vpn.initialize())
    {
        std::cout << "VPN initialized successfully!" << std::endl;
        vpn.run();
    }
    else
    {
        std::cerr << "Failed to initialize VPN!" << std::endl;
    }

    return 0;
}
