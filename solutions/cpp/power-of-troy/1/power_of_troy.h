#pragma once

#include <string>
#include <memory>
#include <string>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

class human { 

    public:
        std::unique_ptr<artifact> possession{nullptr};
        std::shared_ptr<power> own_power{nullptr};
        std::shared_ptr<power> influenced_by{nullptr};

};

void give_new_artifact(human& human, const std::string);

void exchange_artifacts(std::unique_ptr<artifact>& one, std::unique_ptr<artifact>& other);

void manifest_power(human& human, const std::string powerName);

void use_power(const human& caster, human& target);

int power_intensity(const human& human);
    
}  // namespace troy
