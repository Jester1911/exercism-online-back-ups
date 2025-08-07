#include "doctor_data.h"

namespace heaven {

    heaven::Vessel::Vessel(std::string name, int generation, star_map::System current_system) {
        this->name = name;
        this->generation = generation;
        this->current_system = current_system;
    }

    heaven::Vessel  heaven::Vessel::replicate(std::string name) {
        heaven::Vessel clone(name, this->generation, this->current_system);
        ++clone.generation;
        return clone;
    }

    void heaven::Vessel::make_buster() {
        this->busters++;
    }

    bool heaven::Vessel::shoot_buster() {
        if (this->busters > 0) {
            this->busters--;
            return true;
        } else {
            this->busters = 0;
            return false;
        }
    }

    bool in_the_same_system(heaven::Vessel a, heaven::Vessel b) {
        return a.current_system == b.current_system;
    }

    std::string get_older_bob(heaven::Vessel a, heaven::Vessel b) {
        if (a.generation < b.generation) {
            return a.name;
        } else {
            return b.name;
        }
    }



    
}