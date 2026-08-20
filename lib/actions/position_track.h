#include "../attributes.h"
#include "../utils.h"
struct position_track {
    int floor = 0;
    std::optional<double> position_offset_x = std::nullopt;
    std::optional<double> position_offset_y = std::nullopt;
    int relative_to = 0;
    std::string_view relative_to_type = tile_type::this_tile;
    std::optional<double> rotation = std::nullopt;
    std::optional<double> scale = std::nullopt;
    std::optional<double> opacity = std::nullopt;
    bool just_this_tile = false;
    bool editor_only = false;
    std::optional<bool> stick_to_floors = std::nullopt;
    constexpr std::string to_string() const {
        return std::format(
            R"({{"floor":{},"eventType":"PositionTrack",{}"relativeTo":[{},"{}"],{}{}{}"justThisTile":{},"editorOnly":{},{}}},)",
            floor, get_kv("positionOffset", position_offset_x, position_offset_y), relative_to,
            relative_to_type, get_kv("rotation", rotation), get_kv("scale", scale),
            get_kv("opacity", opacity), just_this_tile, editor_only,
            get_kv("stickToFloors", stick_to_floors));
    }
};
