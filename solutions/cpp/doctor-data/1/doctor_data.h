#pragma once
#include <string>

namespace star_map {
    enum class System {
        BetaHydri,
        EpsilonEridani,
        Sol,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {

    class Vessel {
        public:
            Vessel(std::string name, int generation, star_map::System current_system = star_map::System::Sol);
            std::string name{""};
            int generation{};
            star_map::System current_system{};
            int busters{};

            Vessel replicate(std::string name);
            void make_buster();
            bool shoot_buster();
            
        private:
        
    };

    bool in_the_same_system(Vessel a, Vessel b);

    std::string get_older_bob(Vessel a, Vessel b);
}

