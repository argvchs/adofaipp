#include "../utils.h"
struct set_text {
    int floor = 0;
    std::string_view dec_text = "Text";
    std::string_view tag = "";
    float angle_offset = 0;
    std::string_view event_tag = "";
    constexpr std::string to_string() const {
        return std::format(
            R"({{"floor":{},"eventType":"SetText","decText":"{}","tag":"{}","angleOffset":{},"eventTag":"{}"}},)",
            floor, dec_text, tag, angle_offset, event_tag);
    }
};
