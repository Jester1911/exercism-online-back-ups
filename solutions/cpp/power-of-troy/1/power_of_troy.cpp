#include "power_of_troy.h"

namespace troy {


    void give_new_artifact (human& human, const std::string artifactName) {
        human.possession = std::make_unique<artifact>(artifactName);
    }

    void exchange_artifacts(std::unique_ptr<artifact>& one, std::unique_ptr<artifact>& other) {
        // std::unique_ptr is not copyable
        std::swap(one, other);
    }

    void manifest_power(human& human, const std::string powerName) {
        std::shared_ptr<power> newPower = std::make_unique<power>(powerName);
        human.own_power = newPower;
    }

    void use_power(const human& caster, human& target) {
        target.influenced_by = caster.own_power;
    }

    int power_intensity(const human& human) {
        if (human.own_power == nullptr) {
            return 0;
        } else {
            return human.own_power.use_count();
        }
    }
    
}  // namespace troy
