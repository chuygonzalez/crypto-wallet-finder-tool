#ifndef WALLET_FINDER_H
#define WALLET_FINDER_H

#include <string>
#include <vector>

class WalletFinder {
public:
    WalletFinder() = default;
    
    // Generate a random private key (hex string)
    std::string generate_private_key();
    
    // Derive Bitcoin address from private key (simplified: first 20 bytes of SHA-256)
    std::string private_key_to_address(const std::string& private_key_hex);
    
    // Search for wallets starting with a given prefix
    std::vector<std::string> find_wallets_with_prefix(const std::string& prefix, int count);
};

#endif // WALLET_FINDER_H