#include "../attributes.h"
#include "../utils.h"
struct move_decorations {
    int floor = 0;
    float duration = 1;
    std::string_view tag = "sampleTag";
    std::optional<bool> visible = std::nullopt;
    std::optional<std::string_view> relative_to = std::nullopt;
    std::optional<std::string_view> decoration_image = std::nullopt;
    std::optional<float> position_offset_x = std::nullopt;
    std::optional<float> position_offset_y = std::nullopt;
    std::optional<float> pivot_offset_x = std::nullopt;
    std::optional<float> pivot_offset_y = std::nullopt;
    std::optional<float> rotation_offset = std::nullopt;
    std::optional<float> scale_x = std::nullopt;
    std::optional<float> scale_y = std::nullopt;
    std::optional<std::string_view> color = std::nullopt;
    std::optional<float> opacity = std::nullopt;
    std::optional<int> depth = std::nullopt;
    std::optional<float> parallax_x = std::nullopt;
    std::optional<float> parallax_y = std::nullopt;
    std::optional<float> parallax_offset_x = std::nullopt;
    std::optional<float> parallax_offset_y = std::nullopt;
    float angle_offset = 0;
    std::string_view ease = ease::linear;
    std::string_view event_tag = "";
    std::optional<std::string_view> masking_type = std::nullopt;
    std::optional<bool> use_masking_depth = std::nullopt;
    std::optional<int> masking_front_depth = std::nullopt;
    std::optional<int> masking_back_depth = std::nullopt;
    constexpr std::string to_string() const {
        return std::format(
            R"({{"floor":{},"eventType":"MoveDecorations","duration":{},"tag":"{}",{}{}{}{}{}{}{}{}{}{}{}{}"angleOffset":{},"ease":"{}","eventTag":"{}",{}{}{}{}}},)",
            floor, duration, tag, get_kv("visible", visible), get_kv("relativeTo", relative_to),
            get_kv("decorationImage", decoration_image),
            get_kv("positionOffset", position_offset_x, position_offset_y),
            get_kv("pivotOffset", pivot_offset_x, pivot_offset_y),
            get_kv("rotationOffset", rotation_offset), get_kv("scale", scale_x, scale_y),
            get_kv("color", color), get_kv("opacity", opacity), get_kv("depth", depth),
            get_kv("parallax", parallax_x, parallax_y),
            get_kv("parallaxOffset", parallax_offset_x, parallax_offset_y), angle_offset, ease,
            event_tag, get_kv("maskingType", masking_type),
            get_kv("useMaskingDepth", use_masking_depth),
            get_kv("maskingFrontDepth", masking_front_depth),
            get_kv("maskingBackDepth", masking_back_depth));
    }
};
