cmake_minimum_required(VERSION 3.10)

project(deePN-vpn VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#executable and source files
add_executable(deePN-vpn
    src/main.cpp
    src/vpn.cpp
    src/net_utils.cpp
    src/tunnel.cpp
)

include_directories(include)

# linking OpenSSL for encryption
find_package(OpenSSL REQUIRED)
target_link_libraries(deePN-vpn OpenSSL::SSL OpenSSL::Crypto)

install(TARGETS deePN-vpn DESTINATION /usr/local/bin)
