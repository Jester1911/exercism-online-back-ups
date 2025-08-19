#include "grade_school.h"
#include <algorithm>

namespace grade_school {

    std::map<int, std::vector<std::string>> school::roster() const {
        return this->rosterMap;
    }

    bool school::nameExistsInVec(std::vector<std::string>& v, std::string name) {
        for (std::string s : v) {
            if (s == name) {
                return true;
            }
        }
        return false;
    }
    
    void school::add(std::string name, int grade) {
        auto it = this->rosterMap.find(grade);
        if ( it != this->rosterMap.end()) {
            if (!this->nameExistsInVec(it->second, name)) {
                it->second.push_back(name);
                std::sort(it->second.begin(), it->second.end());
            }
            
        } else {
            // No key of that grade yet; can create entry and push
            this->rosterMap[grade].push_back(name);
        }
    }

    std::vector<std::string> school::grade(int num) const {
        if (auto it = this->rosterMap.find(num); it != this->rosterMap.end()) {
            return it->second;
        } else {
            return {};
        }
    }

}  // namespace grade_school
