#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

bool connection_check(pillar_men_sensor* sensor) {
    return sensor != nullptr;
}

int activity_counter(pillar_men_sensor* sensor_array, size_t size) {
    int total{0};
    for (size_t i = 0; i < size; ++i) {
        if (connection_check(sensor_array)) {
            total += sensor_array[i].activity; // I believe index access implicitly derefences pointer, thus dot-notation
            }
        }
    return total;
} 

bool alarm_control(pillar_men_sensor* sensor) {
    if (!connection_check(sensor)) {
        return false;
    }

    // Argument is a pointer, so I believe I need arrow notation as I must follow the pointer to its member
    // since I do not have a copy of the data
    if (sensor->activity > 0) {
        return true;
    } else {
        return false;
    }
}
   
// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool uv_alarm(pillar_men_sensor* sensor) {
    if (!connection_check(sensor)) {
        return false;
    }

    int uv = uv_light_heuristic(&sensor->data);

    // Argument is a pointer, so I must use arrow notation to follow the pointer
    if (uv < sensor->activity) {
        return false;
    } else {
        return true;
    }
} 
    
    
}  // namespace speedywagon
