#pragma once
#include <string>
#include <map>
#include <vector>


namespace grade_school {

    class school {

        public:
            school() = default;
            std::map<int, std::vector<std::string>> roster() const;
            void add(std::string name, int grade);
            std::vector<std::string> grade(int gradeNum) const;
    
        private:
            std::map<int, std::vector<std::string>> rosterMap{};
            bool nameExistsInVec(std::vector<std::string>& v, std::string name);
    };

}  // namespace grade_school
