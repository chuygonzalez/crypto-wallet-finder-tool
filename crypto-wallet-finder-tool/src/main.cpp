#include <iostream>
#include "wallet_finder.h"

int main(int argc, char* argv[]) {
    std::string prefix = "1a";
    int count = 3;
    
    if (argc >= 2) prefix = argv[1];
    if (argc >= 3) count = std::stoi(argv[2]);
    
    std::cout << "Crypto Wallet Finder Tool v1.0" << std::endl;
    std::cout << "Searching for wallets with prefix: " << prefix << std::endl;
    std::cout << "Target count: " << count << std::endl;
    std::cout << "--------------------------------" << std::endl;
    
    WalletFinder finder;
    auto wallets = finder.find_wallets_with_prefix(prefix, count);
    
    if (wallets.empty()) {
        std::cout << "No wallets found with prefix '" << prefix << "' in search space." << std::endl;
    } else {
        std::cout << "Found " << wallets.size() << " wallet(s):" << std::endl;
        for (const auto& w : wallets) {
            std::cout << w << std::endl;
        }
    }
    
    return 0;
}