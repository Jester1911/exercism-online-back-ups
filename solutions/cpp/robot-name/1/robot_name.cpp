#include "robot_name.h"
#include <string>
#include <unordered_map>
#include <random>
#include <iostream>

namespace robot_name {
    
            robot::robot() {
                if (robotName.empty()) {
                    robotName = createName();
                }
            };

            std::string robot::name() const {
                if (robotName.empty()) {
                    robotName = createName();
                }
                 return robotName;
            }

            void robot::reset() {
                //existingNames.erase(robotName);
                robotName = "";
            }
    
            char robot::getRandNumber() const {
                return static_cast<char>('0' + (distNum(rng)));
            }

            char robot::getRandLetter() const {
                return static_cast<char>('A' + (distLetter(rng)));
            }

            bool robot::nameExists (std::string name) const {
                return existingNames.find(name) != existingNames.end();
            }
            
            std::string robot::createName() const {
                std::string result{""};
                bool hasUniqueName{false};
                
                while (!hasUniqueName) {

                    for (int i = 0; i < 2; ++i) {
                        result += getRandLetter();
                    }
    
                    for (int i = 0; i < 3; ++i) {
                        result += getRandNumber();
                    }
                    
                    if (nameExists(result)) {
                        result = "";
                    } else {
                        hasUniqueName = true;
                        existingNames[result] = true;
                    }                   
                }
                return result;
            }

}  // namespace robot_name
