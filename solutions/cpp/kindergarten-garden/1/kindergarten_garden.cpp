#include "kindergarten_garden.h"
#include <unordered_map>
#include <vector>
#include <iostream>

namespace kindergarten_garden {

    Plants mapLetterToPlant(const char letter) {
        Plants plantType{};
        if (letter == 'G') {
            plantType = Plants::grass;
            
        } else if (letter == 'C') {
            plantType = Plants::clover;
            
        } else if (letter == 'R') {
            plantType = Plants::radishes;
            
        } else {
            plantType = Plants::violets;
        }

        return plantType;
    }
    
    std::array<Plants, 4> plants(std::string garden, std::string student) {

        // Init Map
        std::unordered_map<std::string, size_t> studentMap{};
        std::vector<std::string> studentVec{
            "Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny",
            "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
        };
        size_t i = 0;
        for (std::string e : studentVec) {
            studentMap[e] = i;
            ++i;
        }

        // Algorithm
        size_t studentOffset{studentMap[student]};
        const size_t STUDENT_CHAR_INTERVAL{2};
        std::array<char, 4> letters{'0', '0', '0', '0'};
        std::string secondLine = ""; 
        std::array<Plants, 4> result{};
        
        // Find end of first line, beginning of second
        size_t pos = garden.find('\n');
        if (pos != std::string::npos) {
            secondLine = garden.substr(pos + 1);
        }

        for (size_t i = 0; i < 4; ++i) {
            std::string s = "";
            if (i < 2) {
                s = garden;
            } else {
                s = secondLine;
            }

            // Acquire first or second char of student's "group"
            if (i % 2 == 0) {
                letters[i] = s[studentOffset * STUDENT_CHAR_INTERVAL];    
            } else {
                letters[i] = s[studentOffset * STUDENT_CHAR_INTERVAL + 1];
            }
        }
            
        for (int i = 0; i < 4; ++i) {
            result[i] = mapLetterToPlant(letters[i]);
        }

        return result;
        

        
        
    





        


        
        




        
    }

}  // namespace kindergarten_garden
