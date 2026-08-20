#include "../attributes.h"
#include "../utils.h"
struct set_speed {
    int floor = 0;
    std::string_view speed_type = speed_type::bpm;
    double beats_per_minute = 100;
    double bpm_multiplier = 1;
    double angle_offset = 0;
    constexpr std::string to_string() const {
        return std::format(
            R"({{"floor":{},"eventType":"SetSpeed","speedType":"{}","beatsPerMinute":{},"bpmMultiplier":{},"angleOffset":{}}},)",
            floor, speed_type, beats_per_minute, bpm_multiplier, angle_offset);
    }
};
