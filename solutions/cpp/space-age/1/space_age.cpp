#include "space_age.h"
#include <cmath>

namespace space_age {

    space_age::space_age(long long input) {
        ageSecs = input;
        conversions["Mercury"] = 0.2408467;
        conversions["Venus"] = 0.61519726;
        conversions["Earth"] = 1.0;
        conversions["Mars"] = 1.8808158;
        conversions["Jupiter"] = 11.862615;
        conversions["Saturn"] = 29.447498;
        conversions["Uranus"] = 84.016846;
        conversions["Neptune"] = 164.79132;
    }

    long long space_age::seconds() const {
        return ageSecs;
    }
    
    double space_age::convert(long long age, float factor) const {
        if (factor != 0) {
            return (age / secsInYear) / factor;
        } else {
            return -1.0;
        }
    }

    double space_age::on_mercury() const {
        return convert(ageSecs, conversions.at("Mercury"));
    }

    double space_age::on_venus() const {
        return convert(ageSecs, conversions.at("Venus"));
    }

    double space_age::on_earth() const {
        return convert(ageSecs, conversions.at("Earth"));
    }
    
    double space_age::on_mars() const {
        return convert(ageSecs, conversions.at("Mars"));
    }
    
    double space_age::on_jupiter() const {
        return convert(ageSecs, conversions.at("Jupiter"));
    }

    double space_age::on_saturn() const {
        return convert(ageSecs, conversions.at("Saturn"));
    }
    
    double space_age::on_uranus() const {
        return convert(ageSecs, conversions.at("Uranus"));
    }

    double space_age::on_neptune() const {
        return convert(ageSecs, conversions.at("Neptune"));
    }

}  // namespace space_age
