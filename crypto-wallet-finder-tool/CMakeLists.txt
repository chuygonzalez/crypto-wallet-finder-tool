cmake_minimum_required(VERSION 3.10)
project(crypto-wallet-finder-tool VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies: OpenSSL for SHA-256
find_package(OpenSSL REQUIRED)

add_executable(crypto-wallet-finder-tool
    src/main.cpp
    src/wallet_finder.cpp
    src/hash_utils.cpp
)

target_include_directories(crypto-wallet-finder-tool PRIVATE include)
target_link_libraries(crypto-wallet-finder-tool OpenSSL::Crypto)

# Test target
enable_testing()
add_executable(test_wallet_finder
    tests/test_wallet_finder.cpp
    src/wallet_finder.cpp
    src/hash_utils.cpp
)
target_include_directories(test_wallet_finder PRIVATE include)
target_link_libraries(test_wallet_finder OpenSSL::Crypto)
add_test(NAME WalletFinderTests COMMAND test_wallet_finder)