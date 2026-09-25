#include "../attributes.h"
#include "../utils.h"
struct add_text {
    std::optional<int> floor = std::nullopt;
    std::optional<bool> visible = std::nullopt;
    std::optional<bool> locked = std::nullopt;
    std::string_view dec_text = "Text";
    std::string_view tag = "";
    std::string_view font = font::_default;
    float position_x = 0;
    float position_y = 0;
    std::string_view relative_to = relative_to::global;
    float pivot_offset_x = 0;
    float pivot_offset_y = 0;
    float rotation = 0;
    bool lock_rotation = false;
    float scale_x = 100;
    float scale_y = 100;
    bool lock_scale = false;
    std::string_view color = "ffffff";
    float opacity = 100;
    int depth = -1;
    float parallax_x = 0;
    float parallax_y = 0;
    float parallax_offset_x = 0;
    float parallax_offset_y = 0;
    constexpr std::string to_string() const {
        return std::format(
            R"({{{}"eventType":"AddText",{}{}"decText":"{}","tag":"{}","font":"{}","position":[{},{}],"relativeTo":"{}","pivotOffset":[{},{}],"rotation":{},"lockRotation":{},"scale":[{},{}],"lockScale":{},"color":"{}","opacity":{},"depth":{},"parallax":[{},{}],"parallaxOffset":[{},{}]}},)",
            get_kv("floor", floor), get_kv("visible", visible), get_kv("locked", locked), dec_text,
            tag, font, position_x, position_y, relative_to, pivot_offset_x, pivot_offset_y,
            rotation, lock_rotation, scale_x, scale_y, lock_scale, color, opacity, depth,
            parallax_x, parallax_y, parallax_offset_x, parallax_offset_y);
    }
};
