#include <tuple>

namespace targets {

    class Alien {
        public:
            Alien(int x, int y) {
                x_coordinate = x;
                y_coordinate = y;
            }

            int get_health() {
                return health;
            }

            bool hit() {
                if (health > 0) {
                    health--;
                }

                return true;
            } 

            bool is_alive() {
                if (health > 0) {
                    return true;
                } else {
                    return false;
                }
            }

            bool teleport(int x_new, int y_new) {
                x_coordinate = x_new;
                y_coordinate = y_new;
                return true;
            }

            
            std::tuple<int, int> get_coordinates() {
                return std::make_tuple(x_coordinate, y_coordinate);
            }
    
            bool collision_detection(Alien other) {
                auto coords = other.get_coordinates();
                if (std::get<0>(coords) == x_coordinate) {
                    if (std::get<1>(coords) == y_coordinate) {
                        return true;
                    }
                }
                return false;
            }

            int x_coordinate{0};
            int y_coordinate{0};
    
        private:
            int health{3};
    
    };

}  // namespace targets