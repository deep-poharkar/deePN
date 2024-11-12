# deePN - A Basic VPN Implementation

`deePN` is a simple, VPN implementation in C++ designed to understand the fundamental concepts behind VPNs, such as tunneling, encryption, and network communication. It provides a basic VPN tunnel simulation.

## Features

- Establishes a VPN tunnel to a specified server.
- Simulates data encryption during the tunnel connection.
- Provides basic error handling and log output for debugging.
- Designed to run on macOS (M1), but can be easily adapted for other platforms.

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/deePN.git
   cd deePN
   ```

2. Install dependencies (make sure you have cmake and a C++ compiler installed, such as g++).
   On macOS, you can use Homebrew:
   ```bash
   brew install cmake
   ```
3. Build the project:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the project:

   ```bash
   ./deePN-vpn
   ```

   You should see the following output:

   ```bash
   Starting deePN VPN...
   Initializing VPN connection to vpn.example.com on port 1194...
   VPN initialized successfully!
   VPN tunnel established. Data encryption in progress...

   ```
