#ifndef HASH_UTILS_H
#define HASH_UTILS_H

#include <string>

namespace hash_utils {
    // Compute SHA-256 hash of input string, return hex string
    std::string sha256(const std::string& input);
    
    // Convert hex string to bytes
    std::vector<unsigned char> hex_to_bytes(const std::string& hex);
    
    // Convert bytes to hex string
    std::string bytes_to_hex(const std::vector<unsigned char>& bytes);
}

#endif // HASH_UTILS_H