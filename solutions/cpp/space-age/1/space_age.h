#pragma once
#include <unordered_map>
#include <string>

namespace space_age {

    class space_age {
    public:
        space_age(long long input);

        double on_earth() const;
        double on_mercury() const;
        double on_venus() const;
        double on_mars() const;
        double on_saturn() const;
        double on_jupiter() const;
        double on_uranus() const;
        double on_neptune() const;
        long long seconds() const;

    private:
        long long ageSecs{0};
        std::unordered_map<std::string, float> conversions{};
        const double secsInYear{31557600};

        double convert(long long age, float factor) const;
    };

}  // namespace space_age
