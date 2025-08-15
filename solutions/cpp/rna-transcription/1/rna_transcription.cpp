#include "rna_transcription.h"
#include <unordered_map>
#include <string>
#include <iostream>



namespace rna_transcription {

    std::string mapNucleotideDnaToRna(std::string input) {
        // Init unordered map for DNA->RNA key-value pairs
        std::unordered_map<std::string, std::string> rnaMap{
            {"G", "C"},
            {"C", "G"},
            {"T", "A"},
            {"A", "U"}
        };
        
        if (auto it = rnaMap.find(input); it != rnaMap.end()) { 
            // Return 0 element of std::string to conform to expected char return type
            return it->second;
        } else {
            return "";
        }
    }

    // Use overloads to handle different input and expected return data types
    // NOTE: std::to_string ONLY works with numeric types. So must create instances 
    // of the string equivalent of the char letter.
    
   char to_rna(char input) {
       std::string letter{std::string(1, input)};
       std::string result{mapNucleotideDnaToRna(letter)};
       return result[0];
   }

    std::string to_rna(std::string input) {
        std::string result{""};

        for (char element : input) {
            std::string letter{std::string(1, element)};
            result += mapNucleotideDnaToRna(letter);
        }
        return result;
    }

    
}  // namespace rna_transcription
