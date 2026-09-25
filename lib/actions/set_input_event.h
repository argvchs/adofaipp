#include "../utils.h"
#include "../attributes.h"
struct set_input_event {
    int floor = 0;
    std::string_view target = target::any;
    std::string_view state = state::down;
    bool ignore_input = false;
    std::string_view target_event_tag = "NONE";
    float angle_offset = 0;
    std::string_view event_tag = "";
    constexpr std::string to_string() const {
        return std::format(
            R"({{"floor":{},"eventType":"SetInputEvent","target":"{}","state":"{}","ignoreInput":{},"targetEventTag":"{}","angleOffset":{},"eventTag":"{}"}},)",
            floor, target, state, ignore_input, target_event_tag, angle_offset, event_tag);
    }
};
