#include <iostream>
#include <cassert>
#include "wallet_finder.h"
#include "hash_utils.h"

void test_hash_utils() {
    std::cout << "Testing hash_utils..." << std::endl;
    
    // Test SHA-256 with known value
    std::string hash = hash_utils::sha256("hello");
    assert(hash.length() == 64);
    std::cout << "  SHA-256('hello') = " << hash << std::endl;
    
    // Test hex conversion
    auto bytes = hash_utils::hex_to_bytes("aabb");
    assert(bytes.size() == 2);
    assert(bytes[0] == 0xaa);
    assert(bytes[1] == 0xbb);
    
    auto hex = hash_utils::bytes_to_hex(bytes);
    assert(hex == "aabb");
    
    std::cout << "  Hex conversion: OK" << std::endl;
}

void test_wallet_finder() {
    std::cout << "Testing WalletFinder..." << std::endl;
    
    WalletFinder finder;
    
    // Test private key generation
    std::string key1 = finder.generate_private_key();
    std::string key2 = finder.generate_private_key();
    assert(key1.length() == 64);
    assert(key1 != key2);
    std::cout << "  Private key generation: OK" << std::endl;
    
    // Test address derivation
    std::string address = finder.private_key_to_address(key1);
    assert(address.length() == 40);
    assert(address[0] == '1');
    std::cout << "  Address derivation: OK" << std::endl;
    
    // Test prefix search (may return 0 if unlucky)
    auto wallets = finder.find_wallets_with_prefix("1x", 1);
    std::cout << "  Prefix search (1x): found " << wallets.size() << " wallets" << std::endl;
}

int main() {
    std::cout << "Running Crypto Wallet Finder tests..." << std::endl;
    
    test_hash_utils();
    test_wallet_finder();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}