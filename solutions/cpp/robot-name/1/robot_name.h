#pragma once
#include <string>
#include <unordered_map>
#include <random>
#include <iostream>

namespace robot_name {

    class robot {
    public:
        robot();
        std::string name() const;
        void reset();
    
    private:
        static inline std::mt19937 rng{std::random_device{}()};
        static inline std::uniform_int_distribution<int> distNum{0,9};
        static inline std::uniform_int_distribution<int> distLetter{0,25};
        static inline std::unordered_map<std::string, bool> existingNames;

        mutable std::string robotName;

        char getRandNumber() const;
        char getRandLetter() const;
        bool nameExists(std::string name) const;
        std::string createName() const;
    };

} // namespace robot_name