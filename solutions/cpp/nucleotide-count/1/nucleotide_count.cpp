#include "nucleotide_count.h"
#include <map>
#include <stdexcept>


namespace nucleotide_count {
    
    std::map<char, int> count(std::string dna) {
        std::map<char, int> nucMap{
            {'A', 0},
            {'C', 0}, 
            {'G', 0},
            {'T', 0}
        };
        
        for (char c : dna) {
            if (nucMap.find(c) != nucMap.end()) {
                nucMap[c] += 1;
            } else {
                throw std::invalid_argument("Invalid nucleotide character.");
            }
        }
        
        return nucMap;
    }

}  // namespace nucleotide_count
