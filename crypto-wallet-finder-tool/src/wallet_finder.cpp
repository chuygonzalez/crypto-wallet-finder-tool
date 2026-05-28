#include "wallet_finder.h"
#include "hash_utils.h"
#include <random>
#include <algorithm>

std::string WalletFinder::generate_private_key() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);
    
    std::string key;
    for (int i = 0; i < 64; ++i) {
        key += "0123456789abcdef"[dis(gen)];
    }
    return key;
}

std::string WalletFinder::private_key_to_address(const std::string& private_key_hex) {
    // Simplified: derive address by double SHA-256, take first 20 bytes
    std::string hash1 = hash_utils::sha256(private_key_hex);
    std::string hash2 = hash_utils::sha256(hash1);
    
    // Take first 40 hex chars (20 bytes) as address
    std::string address = "1";
    address += hash2.substr(0, 39); // Simulate base58-like prefix
    return address;
}

std::vector<std::string> WalletFinder::find_wallets_with_prefix(const std::string& prefix, int count) {
    std::vector<std::string> wallets;
    int found = 0;
    int attempts = 0;
    const int max_attempts = 100000;
    
    while (found < count && attempts < max_attempts) {
        std::string priv_key = generate_private_key();
        std::string address = private_key_to_address(priv_key);
        
        if (address.substr(0, prefix.length()) == prefix) {
            wallets.push_back("PK: " + priv_key + " -> Addr: " + address);
            found++;
        }
        attempts++;
    }
    
    return wallets;
}