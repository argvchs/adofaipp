#include "../attributes.h"
#include "../utils.h"
#include <format>
struct move_track {
    int floor = 0;
    int start_tile = 0;
    std::string_view start_tile_type = tile_type::this_tile;
    int end_tile = 0;
    std::string_view end_tile_type = tile_type::this_tile;
    int gap_length = 0;
    double duration = 1;
    std::optional<double> position_offset_x = std::nullopt;
    std::optional<double> position_offset_y = std::nullopt;
    std::optional<double> rotation_offset = std::nullopt;
    std::optional<double> scale_x = std::nullopt;
    std::optional<double> scale_y = std::nullopt;
    std::optional<double> opacity = std::nullopt;
    double angle_offset = 0;
    std::string_view ease = ease::linear;
    std::string_view event_tag = "";
    constexpr std::string to_string() const {
        return std::format(
            R"({{"floor":{},"eventType":"MoveTrack","startTile":[{},"{}"],"endTile":[{},"{}"],"gapLength":{},"duration":{},{}{}{}{}"angleOffset":{},"ease":"{}","eventTag":"{}"}},)",
            floor, start_tile, start_tile_type, end_tile, end_tile_type, gap_length, duration,
            get_kv("positionOffset", position_offset_x, position_offset_y),
            get_kv("rotationOffset", rotation_offset), get_kv("scale", scale_x, scale_y),
            get_kv("opacity", opacity), angle_offset, ease, event_tag);
    }
};
