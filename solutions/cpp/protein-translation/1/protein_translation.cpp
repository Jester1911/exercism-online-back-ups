#include "protein_translation.h"
#include<vector>
#include<string>
#include<unordered_map>

namespace protein_translation {

    std::vector<std::string> proteins(std::string sequence) {
    
        // init dictionary
        std::unordered_map<std::string, std::string> proteinMap{};
        proteinMap["AUG"] = "Methionine";
        proteinMap["UUU"] = "Phenylalanine";
        proteinMap["UUC"] = "Phenylalanine";
        proteinMap["UUA"] = "Leucine";
        proteinMap["UUG"] = "Leucine";
        proteinMap["UCU"] = "Serine";
        proteinMap["UCC"] = "Serine";
        proteinMap["UCA"] = "Serine";
        proteinMap["UCG"] = "Serine";
        proteinMap["UAU"] = "Tyrosine";
        proteinMap["UAC"] = "Tyrosine";
        proteinMap["UGU"] = "Cysteine";
        proteinMap["UGC"] = "Cysteine";
        proteinMap["UGG"] = "Tryptophan";
        proteinMap["UAA"] = "STOP";
        proteinMap["UAG"] = "STOP";
        proteinMap["UGA"] = "STOP";

        // algorithm
        std::vector<std::string> result{};
        for (size_t i = 0; i < sequence.size(); i+=3) {
            std::string slice = sequence.substr(i, 3);

            if (proteinMap[slice] == "STOP") {
                break;
            } else {
                result.push_back(proteinMap[slice]);
            }
        }

        return result;
    }    

}  // namespace protein_translation
